#include "flash_test.h"
#include "debug.h"

typedef enum
{
    FAILED = 0,
    PASSED = !FAILED
} TestStatus;

#define PAGE_WRITE_START_ADDR  ((uint32_t)0x08008000) /* Start from 32K */
#define PAGE_WRITE_END_ADDR    ((uint32_t)0x08009000) /* End at 36K */
#define FLASH_PAGE_SIZE                   4096

/* Fast Mode define */
#define FAST_FLASH_PROGRAM_START_ADDR  ((uint32_t)0x08008000)
#define FAST_FLASH_PROGRAM_END_ADDR  ((uint32_t)0x08010000)
#define FAST_FLASH_SIZE  (64*1024)

/* Global Variable */
uint32_t EraseCounter = 0x0, Address = 0x0;
uint16_t Data = 0xAAAA;
uint32_t WRPR_Value = 0xFFFFFFFF, ProtectedPages = 0x0;
uint32_t NbrOfPage;
volatile FLASH_Status FLASHStatus = FLASH_COMPLETE;
volatile TestStatus MemoryProgramStatus = PASSED;
volatile TestStatus MemoryEraseStatus = PASSED;
u32 buf[64];

/*********************************************************************
 * @fn      Flash_Test
 *
 * @brief   Flash Program Test.
 *
 * @return  none
 */
void Flash_Test(void)
{
    printf("FLASH Test\r\n");
 /*When the main frequency exceeds 100MHz, attention should be paid when
  *operating FLASH: dividing HCLK by two will result in the related peripheral
  *clock of HCLK being divided by two. Attention should be paid when using.
  */
    RCC->CFGR0 |= (uint32_t)RCC_HPRE_DIV2;
    __disable_irq();
    USART_Printf_Init(115200);

    FLASH_Unlock();

    NbrOfPage = (PAGE_WRITE_END_ADDR - PAGE_WRITE_START_ADDR) / FLASH_PAGE_SIZE;

    FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP |FLASH_FLAG_WRPRTERR);

    for(EraseCounter = 0; (EraseCounter < NbrOfPage) && (FLASHStatus == FLASH_COMPLETE); EraseCounter++)
    {
      FLASHStatus = FLASH_ErasePage(PAGE_WRITE_START_ADDR + (FLASH_PAGE_SIZE * EraseCounter));  //Erase 4KB

      if(FLASHStatus != FLASH_COMPLETE)
      {
        printf("FLASH Erase Fail\r\n");
      }
      printf("FLASH Erase Suc\r\n");
    }

    Address = PAGE_WRITE_START_ADDR;
    printf("Programing...\r\n");
    while((Address < PAGE_WRITE_END_ADDR) && (FLASHStatus == FLASH_COMPLETE))
    {
      FLASHStatus = FLASH_ProgramHalfWord(Address, Data);
      Address = Address + 2;
    }

    Address = PAGE_WRITE_START_ADDR;

    printf("Program Cheking...\r\n");
    while((Address < PAGE_WRITE_END_ADDR) && (MemoryProgramStatus != FAILED))
    {
      if((*(__IO uint16_t*) Address) != Data)
      {
        MemoryProgramStatus = FAILED;
      }
      Address += 2;
    }

    if(MemoryProgramStatus == FAILED)
    {
       printf("Memory Program FAIL!\r\n");
    }
    else
    {
       printf("Memory Program PASS!\r\n");
    }


     FLASH_Lock();

     RCC->CFGR0 &= ~(uint32_t)RCC_HPRE_DIV2;
     __enable_irq();
     USART_Printf_Init(115200);

}

/*********************************************************************
 * @fn      Flash_Test_Fast
 *
 * @brief   Flash Fast Program Test.
 *
 * @return  none
 */
void Flash_Test_Fast(void)
{
    u16 i,j,flag;

    for(i=0; i<64; i++){
        buf[i] = i;
    }

    printf("FLASH Fast Mode Test\r\n");

    RCC->CFGR0 |= (uint32_t)RCC_HPRE_DIV2;
    __disable_irq();
    USART_Printf_Init(115200);

    FLASH_Unlock_Fast();

    FLASH_EraseBlock_32K_Fast(FAST_FLASH_PROGRAM_START_ADDR);

    printf("Program 32KByte start\r\n");
    for(i=0; i<128; i++){
        FLASH_ProgramPage_Fast(FAST_FLASH_PROGRAM_START_ADDR + 256*i, buf);
    }

    for(i=0; i<128; i++){
        for(j=0; j<64; j++){
            if(*(u32*)(FAST_FLASH_PROGRAM_START_ADDR+256*i+4*j) != j){
                flag = 0;
                break;
            }
            else{
                flag = 1;
            }
        }

    }

    if(flag){
        printf("Program 32KByte suc\r\n");
    }
    else printf("Program fail\r\n");

    printf("Erase 256Byte...\r\n");
    FLASH_ErasePage_Fast(FAST_FLASH_PROGRAM_START_ADDR);

    printf("Read 4KByte...\r\n");
    for(i=0;i<1024; i++){
      printf("%08x ",*(u32*)(FAST_FLASH_PROGRAM_START_ADDR+4*i));

    }printf("\r\n");

    printf("Erase 4KByte...\r\n");
    FLASH_ErasePage(FAST_FLASH_PROGRAM_START_ADDR);

    printf("Read 8KByte...\r\n");
    for(i=0;i<2048; i++){
      printf("%08x ",*(u32*)(FAST_FLASH_PROGRAM_START_ADDR+4*i));

    }printf("\n");

    printf("Erase 32KByte...\r\n");
    FLASH_EraseBlock_32K_Fast(FAST_FLASH_PROGRAM_START_ADDR);

    printf("Read 32KByte...\r\n");
    for(i=0;i<(1024*9); i++){
      printf("%08x ",*(u32*)(FAST_FLASH_PROGRAM_START_ADDR+4*i));

    }printf("\r\n");


    FLASH_Lock_Fast();

    RCC->CFGR0 &= ~(uint32_t)RCC_HPRE_DIV2;
    __enable_irq();
    USART_Printf_Init(115200);
}
