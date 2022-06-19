#ifndef _USB_CH32_USBHD_REG_H
#define _USB_CH32_USBHD_REG_H

#define __IO volatile /* defines 'read / write' permissions */

/* USBOTG_FS Registers */
typedef struct __attribute__((packed))
{
    __IO uint8_t BASE_CTRL;
    __IO uint8_t UDEV_CTRL;
    __IO uint8_t INT_EN;
    __IO uint8_t DEV_ADDR;
    __IO uint8_t Reserve0;
    __IO uint8_t MIS_ST;
    __IO uint8_t INT_FG;
    __IO uint8_t INT_ST;
    __IO uint16_t RX_LEN;
    __IO uint16_t Reserve1;
    __IO uint8_t UEP4_1_MOD;
    __IO uint8_t UEP2_3_MOD;
    __IO uint8_t UEP5_6_MOD;
    __IO uint8_t UEP7_MOD;
    __IO uint32_t UEP0_DMA;
    __IO uint32_t UEP1_DMA;
    __IO uint32_t UEP2_DMA;
    __IO uint32_t UEP3_DMA;
    __IO uint32_t UEP4_DMA;
    __IO uint32_t UEP5_DMA;
    __IO uint32_t UEP6_DMA;
    __IO uint32_t UEP7_DMA;

    __IO uint16_t UEP0_TX_LEN;
    __IO uint8_t UEP0_CTRL;
    __IO uint8_t Reserve2;

    __IO uint16_t UEP1_TX_LEN;
    __IO uint8_t UEP1_CTRL;
    __IO uint8_t Reserve3;

    __IO uint16_t UEP2_TX_LEN;
    __IO uint8_t UEP2_CTRL;
    __IO uint8_t Reserve4;

    __IO uint16_t UEP3_TX_LEN;
    __IO uint8_t UEP3_CTRL;
    __IO uint8_t Reserve5;

    __IO uint16_t UEP4_TX_LEN;
    __IO uint8_t UEP4_CTRL;
    __IO uint8_t Reserve6;

    __IO uint16_t UEP5_TX_LEN;
    __IO uint8_t UEP5_CTRL;
    __IO uint8_t Reserve7;

    __IO uint16_t UEP6_TX_LEN;
    __IO uint8_t UEP6_CTRL;
    __IO uint8_t Reserve8;

    __IO uint16_t UEP7_TX_LEN;
    __IO uint8_t UEP7_CTRL;
    __IO uint8_t Reserve9;
} USBHD_TypeDef;

typedef struct __attribute__((packed))
{
    __IO uint8_t BASE_CTRL;
    __IO uint8_t HOST_CTRL;
    __IO uint8_t INT_EN;
    __IO uint8_t DEV_ADDR;
    __IO uint8_t Reserve0;
    __IO uint8_t MIS_ST;
    __IO uint8_t INT_FG;
    __IO uint8_t INT_ST;
    __IO uint16_t RX_LEN;
    __IO uint16_t Reserve1;
    __IO uint8_t Reserve2;
    __IO uint8_t HOST_EP_MOD;
    __IO uint16_t Reserve3;
    __IO uint32_t Reserve4;
    __IO uint32_t Reserve5;
    __IO uint32_t HOST_RX_DMA;
    __IO uint32_t HOST_TX_DMA;
    __IO uint32_t Reserve6;
    __IO uint32_t Reserve7;
    __IO uint32_t Reserve8;
    __IO uint32_t Reserve9;
    __IO uint32_t Reserve10;
    __IO uint16_t Reserve11;
    __IO uint16_t HOST_SETUP;
    __IO uint8_t HOST_EP_PID;
    __IO uint8_t Reserve12;
    __IO uint8_t Reserve13;
    __IO uint8_t HOST_RX_CTRL;
    __IO uint16_t HOST_TX_LEN;
    __IO uint8_t HOST_TX_CTRL;
} USBHDH_TypeDef;

#define USBHD_BASE ((uint32_t)0x40023400)

#define USBHD_DEVICE ((USBHD_TypeDef *)USBHD_BASE)
#define USBHD_HOST ((USBHDH_TypeDef *)USBHD_BASE)

/******************* GLOBAL ******************/

/* BASE USB_CTRL */
#define USBHD_BASE_CTRL_OFFSET 0x00 // USB base control
#define USBHD_UC_HOST_MODE 0x80     // enable USB host mode: 0=device mode, 1=host mode
#define USBHD_UC_LOW_SPEED 0x40     // enable USB low speed: 0=12Mbps, 1=1.5Mbps
#define USBHD_UC_DEV_PU_EN 0x20     // USB device enable and internal pullup resistance enable
#define USBHD_UC_SYS_CTRL1 0x20     // USB system control high bit
#define USBHD_UC_SYS_CTRL0 0x10     // USB system control low bit
#define USBHD_UC_SYS_CTRL_MASK 0x30 // bit mask of USB system control
// UC_HOST_MODE & UC_SYS_CTRL1 & UC_SYS_CTRL0: USB system control
//   0 00: disable USB device and disable internal pullup resistance
//   0 01: enable USB device and disable internal pullup resistance, need external pullup resistance
//   0 1x: enable USB device and enable internal pullup resistance
//   1 00: enable USB host and normal status
//   1 01: enable USB host and force UDP/UDM output SE0 state
//   1 10: enable USB host and force UDP/UDM output J state
//   1 11: enable USB host and force UDP/UDM output resume or K state
#define USBHD_UC_INT_BUSY 0x08  // enable automatic responding busy for device mode or automatic pause for host mode during interrupt flag UIF_TRANSFER valid
#define USBHD_UC_RESET_SIE 0x04 // force reset USB SIE, need software clear
#define USBHD_UC_CLR_ALL 0x02   // force clear FIFO and count of USB
#define USBHD_UC_DMA_EN 0x01    // DMA enable and DMA interrupt enable for USB

/* USB INT EN */
#define USBHD_INT_EN_OFFSET 0x02
#define USBHD_UIE_DEV_SOF 0x80  // enable interrupt for SOF received for USB device mode
#define USBHD_UIE_DEV_NAK 0x40  // enable interrupt for NAK responded for USB device mode
#define USBHD_UIE_FIFO_OV 0x10  // enable interrupt for FIFO overflow
#define USBHD_UIE_HST_SOF 0x08  // enable interrupt for host SOF timer action for USB host mode
#define USBHD_UIE_SUSPEND 0x04  // enable interrupt for USB suspend or resume event
#define USBHD_UIE_TRANSFER 0x02 // enable interrupt for USB transfer completion
#define USBHD_UIE_DETECT 0x01   // enable interrupt for USB device detected event for USB host mode
#define USBHD_UIE_BUS_RST 0x01  // enable interrupt for USB bus reset event for USB device mode
/* USB_DEV_ADDR */
#define USBHD_DEV_ADDR_OFFSET 0x03
#define USBHD_UDA_GP_BIT 0x80    // general purpose bit
#define USBHD_USB_ADDR_MASK 0x7F // bit mask for USB device address

/* USB_STATUS */
#define USBHD_USB_STATUS_OFFSET 0x04

/* USB_MIS_ST */
#define USBHD_MIS_ST_OFFSET 0x05
#define USBHD_UMS_SOF_PRES 0x80   // RO, indicate host SOF timer presage status
#define USBHD_UMS_SOF_ACT 0x40    // RO, indicate host SOF timer action status for USB host
#define USBHD_UMS_SIE_FREE 0x20   // RO, indicate USB SIE free status
#define USBHD_UMS_R_FIFO_RDY 0x10 // RO, indicate USB receiving FIFO ready status (not empty)
#define USBHD_UMS_BUS_RESET 0x08  // RO, indicate USB bus reset status
#define USBHD_UMS_SUSPEND 0x04    // RO, indicate USB suspend status
#define USBHD_UMS_DM_LEVEL 0x02   // RO, indicate UDM level saved at device attached to USB host
#define USBHD_UMS_DEV_ATTACH 0x01 // RO, indicate device attached status on USB host

/* USB_INT_FG */
#define USBHD_INT_FG_OFFSET 0x06
#define USBHD_U_IS_NAK 0x80     // RO, indicate current USB transfer is NAK received
#define USBHD_U_TOG_OK 0x40     // RO, indicate current USB transfer toggle is OK
#define USBHD_U_SIE_FREE 0x20   // RO, indicate USB SIE free status
#define USBHD_UIF_FIFO_OV 0x10  // FIFO overflow interrupt flag for USB, direct bit address clear or write 1 to clear
#define USBHD_UIF_HST_SOF 0x08  // host SOF timer interrupt flag for USB host, direct bit address clear or write 1 to clear
#define USBHD_UIF_SUSPEND 0x04  // USB suspend or resume event interrupt flag, direct bit address clear or write 1 to clear
#define USBHD_UIF_TRANSFER 0x02 // USB transfer completion interrupt flag, direct bit address clear or write 1 to clear
#define USBHD_UIF_DETECT 0x01   // device detected event interrupt flag for USB host mode, direct bit address clear or write 1 to clear
#define USBHD_UIF_BUS_RST 0x01  // bus reset event interrupt flag for USB device mode, direct bit address clear or write 1 to clear

/* USB_INT_ST */
#define USBHD_INT_ST_OFFSET 0x07
#define USBHD_UIS_IS_SETUP 0x80   // RO, indicate current USB transfer is setup received for USB device mode
#define USBHD_UIS_IS_NAK 0x80     // RO, indicate current USB transfer is NAK received for USB device mode
#define USBHD_UIS_TOG_OK 0x40     // RO, indicate current USB transfer toggle is OK
#define USBHD_UIS_TOKEN1 0x20     // RO, current token PID code bit 1 received for USB device mode
#define USBHD_UIS_TOKEN0 0x10     // RO, current token PID code bit 0 received for USB device mode
#define USBHD_UIS_TOKEN_MASK 0x30 // RO, bit mask of current token PID code received for USB device mode
#define USBHD_UIS_TOKEN_OUT 0x00
#define USBHD_UIS_TOKEN_SOF 0x10
#define USBHD_UIS_TOKEN_IN 0x20
#define USBHD_UIS_TOKEN_SETUP 0x30
// UIS_TOKEN1 & UIS_TOKEN0: current token PID code received for USB device mode
//   00: OUT token PID received
//   01: SOF token PID received
//   10: IN token PID received
//   11: SETUP token PID received
#define USBHD_UIS_ENDP_MASK 0x0F // RO, bit mask of current transfer endpoint number for USB device mode
/* USB_RX_LEN */
#define USBHD_RX_LEN_OFFSET 0x08

/******************* DEVICE ******************/

/* UDEV_CTRL */
#define USBHD_UDEV_CTRL_OFFSET 0x01
#define USBHD_UD_PD_DIS 0x80    // disable USB UDP/UDM pulldown resistance: 0=enable pulldown, 1=disable
#define USBHD_UD_DP_PIN 0x20    // ReadOnly: indicate current UDP pin level
#define USBHD_UD_DM_PIN 0x10    // ReadOnly: indicate current UDM pin level
#define USBHD_UD_LOW_SPEED 0x04 // enable USB physical port low speed: 0=full speed, 1=low speed
#define USBHD_UD_GP_BIT 0x02    // general purpose bit
#define USBHD_UD_PORT_EN 0x01   // enable USB physical port I/O: 0=disable, 1=enable

/* UEP4_1_MOD */
#define USBHD_UEP4_1_MOD_OFFSET 0x0C
#define USBHD_UEP1_RX_EN 0x80   // enable USB endpoint 1 receiving (OUT)
#define USBHD_UEP1_TX_EN 0x40   // enable USB endpoint 1 transmittal (IN)
#define USBHD_UEP1_BUF_MOD 0x10 // buffer mode of USB endpoint 1
// UEPn_RX_EN & UEPn_TX_EN & UEPn_BUF_MOD: USB endpoint 1/2/3 buffer mode, buffer start address is UEPn_DMA
//   0 0 x:  disable endpoint and disable buffer
//   1 0 0:  64 bytes buffer for receiving (OUT endpoint)
//   1 0 1:  dual 64 bytes buffer by toggle bit bUEP_R_TOG selection for receiving (OUT endpoint), total=128bytes
//   0 1 0:  64 bytes buffer for transmittal (IN endpoint)
//   0 1 1:  dual 64 bytes buffer by toggle bit bUEP_T_TOG selection for transmittal (IN endpoint), total=128bytes
//   1 1 0:  64 bytes buffer for receiving (OUT endpoint) + 64 bytes buffer for transmittal (IN endpoint), total=128bytes
//   1 1 1:  dual 64 bytes buffer by bUEP_R_TOG selection for receiving (OUT endpoint) + dual 64 bytes buffer by bUEP_T_TOG selection for transmittal (IN endpoint), total=256bytes
#define USBHD_UEP4_RX_EN 0x08 // enable USB endpoint 4 receiving (OUT)
#define USBHD_UEP4_TX_EN 0x04 // enable USB endpoint 4 transmittal (IN)
// UEP4_RX_EN & UEP4_TX_EN: USB endpoint 4 buffer mode, buffer start address is UEP0_DMA
//   0 0:  single 64 bytes buffer for endpoint 0 receiving & transmittal (OUT & IN endpoint)
//   1 0:  single 64 bytes buffer for endpoint 0 receiving & transmittal (OUT & IN endpoint) + 64 bytes buffer for endpoint 4 receiving (OUT endpoint), total=128bytes
//   0 1:  single 64 bytes buffer for endpoint 0 receiving & transmittal (OUT & IN endpoint) + 64 bytes buffer for endpoint 4 transmittal (IN endpoint), total=128bytes
//   1 1:  single 64 bytes buffer for endpoint 0 receiving & transmittal (OUT & IN endpoint)
//           + 64 bytes buffer for endpoint 4 receiving (OUT endpoint) + 64 bytes buffer for endpoint 4 transmittal (IN endpoint), total=192bytes

/* UEP2_3_MOD */
#define USBHD_UEP2_3_MOD_OFFSET 0x0D
#define USBHD_UEP3_RX_EN 0x80   // enable USB endpoint 3 receiving (OUT)
#define USBHD_UEP3_TX_EN 0x40   // enable USB endpoint 3 transmittal (IN)
#define USBHD_UEP3_BUF_MOD 0x10 // buffer mode of USB endpoint 3
#define USBHD_UEP2_RX_EN 0x08   // enable USB endpoint 2 receiving (OUT)
#define USBHD_UEP2_TX_EN 0x04   // enable USB endpoint 2 transmittal (IN)
#define USBHD_UEP2_BUF_MOD 0x01 // buffer mode of USB endpoint 2

/* UEP5_6_MOD */
#define USBHD_UEP5_6_MOD_OFFSET 0x0E
#define USBHD_UEP6_RX_EN 0x80   // enable USB endpoint 6 receiving (OUT)
#define USBHD_UEP6_TX_EN 0x40   // enable USB endpoint 6 transmittal (IN)
#define USBHD_UEP6_BUF_MOD 0x10 // buffer mode of USB endpoint 6
#define USBHD_UEP5_RX_EN 0x08   // enable USB endpoint 5 receiving (OUT)
#define USBHD_UEP5_TX_EN 0x04   // enable USB endpoint 5 transmittal (IN)
#define USBHD_UEP5_BUF_MOD 0x01 // buffer mode of USB endpoint 5

/* UEP7_MOD */
#define USBHD_UEP7_MOD_OFFSET 0x0F
#define USBHD_UEP7_RX_EN 0x08   // enable USB endpoint 7 receiving (OUT)
#define USBHD_UEP7_TX_EN 0x04   // enable USB endpoint 7 transmittal (IN)
#define USBHD_UEP7_BUF_MOD 0x01 // buffer mode of USB endpoint 7

/* USB_DMA */
#define USBHD_UEPx_DMA_OFFSET(n) (0x10 + 4 * (n)) // endpoint x DMA buffer address
#define USBHD_UEP0_DMA_OFFSET 0x10                // endpoint 0 DMA buffer address
#define USBHD_UEP1_DMA_OFFSET 0x14                // endpoint 1 DMA buffer address
#define USBHD_UEP2_DMA_OFFSET 0x18                // endpoint 2 DMA buffer address
#define USBHD_UEP3_DMA_OFFSET 0x1c                // endpoint 3 DMA buffer address
#define USBHD_UEP4_DMA_OFFSET 0x20                // endpoint 4 DMA buffer address
#define USBHD_UEP5_DMA_OFFSET 0x24                // endpoint 5 DMA buffer address
#define USBHD_UEP6_DMA_OFFSET 0x28                // endpoint 6 DMA buffer address
#define USBHD_UEP7_DMA_OFFSET 0x2c                // endpoint 7 DMA buffer address

/* USB_EP_CTRL */
#define USBHD_UEPx_T_LEN_OFFSET(n) (0x30 + 4 * (n))       // endpoint x DMA buffer address
#define USBHD_UEPx_TX_CTRL_OFFSET(n) (0x30 + 4 * (n) + 2) // endpoint x DMA buffer address
#define USBHD_UEPx_RX_CTRL_OFFSET(n) (0x30 + 4 * (n) + 3) // endpoint x DMA buffer address

#define USBHD_UEP_AUTO_TOG 0x10 // enable automatic toggle after successful transfer completion on endpoint 1/2/3: 0=manual toggle, 1=automatic toggle
#define USBHD_UEP_R_TOG 0x80    // expected data toggle flag of USB endpoint X receiving (OUT): 0=DATA0, 1=DATA1
#define USBHD_UEP_T_TOG 0x40    // prepared data toggle flag of USB endpoint X transmittal (IN): 0=DATA0, 1=DATA1

#define USBHD_UEP_R_RES1 0x08     // handshake response type high bit for USB endpoint X receiving (OUT)
#define USBHD_UEP_R_RES0 0x04     // handshake response type low bit for USB endpoint X receiving (OUT)
#define USBHD_UEP_R_RES_MASK 0x0c // bit mask of handshake response type for USB endpoint X receiving (OUT)
#define USBHD_UEP_R_RES_ACK 0x00
#define USBHD_UEP_R_RES_TOUT 0x04
#define USBHD_UEP_R_RES_NAK 0x08
#define USBHD_UEP_R_RES_STALL 0x0c
// RB_UEP_R_RES1 & RB_UEP_R_RES0: handshake response type for USB endpoint X receiving (OUT)
//   00: ACK (ready)
//   01: no response, time out to host, for non-zero endpoint isochronous transactions
//   10: NAK (busy)
//   11: STALL (error)
#define USBHD_UEP_T_RES1 0x02     // handshake response type high bit for USB endpoint X transmittal (IN)
#define USBHD_UEP_T_RES0 0x01     // handshake response type low bit for USB endpoint X transmittal (IN)
#define USBHD_UEP_T_RES_MASK 0x03 // bit mask of handshake response type for USB endpoint X transmittal (IN)
#define USBHD_UEP_T_RES_ACK 0x00
#define USBHD_UEP_T_RES_TOUT 0x01
#define USBHD_UEP_T_RES_NAK 0x02
#define USBHD_UEP_T_RES_STALL 0x03
// bUEP_T_RES1 & bUEP_T_RES0: handshake response type for USB endpoint X transmittal (IN)
//   00: DATA0 or DATA1 then expecting ACK (ready)
//   01: DATA0 or DATA1 then expecting no response, time out from host, for non-zero endpoint isochronous transactions
//   10: NAK (busy)
//   11: TALL (error)

/******************* HOST ******************/

#define USBHD_UHOST_CTRL_OFFSET 0x01 // USB host physical prot control
#define USBHD_UH_PD_DIS 0x80         // disable USB UDP/UDM pulldown resistance: 0=enable pulldown, 1=disable
#define USBHD_UH_DP_PIN 0x20         // ReadOnly: indicate current UDP pin level
#define USBHD_UH_DM_PIN 0x10         // ReadOnly: indicate current UDM pin level
#define USBHD_UH_LOW_SPEED 0x04      // enable USB port low speed: 0=full speed, 1=low speed
#define USBHD_UH_BUS_RESET 0x02      // control USB bus reset: 0=normal, 1=force bus reset
#define USBHD_UH_PORT_EN 0x01        // enable USB port: 0=disable, 1=enable port, automatic disabled if USB device detached

#define USBHD_UH_EP_MOD_OFFSET USBHD_UEP2_3_MOD_OFFSET
#define USBHD_UH_EP_TX_EN 0x40    // enable USB host OUT endpoint transmittal
#define USBHD_UH_EP_TBUF_MOD 0x10 // buffer mode of USB host OUT endpoint
// bUH_EP_TX_EN & bUH_EP_TBUF_MOD: USB host OUT endpoint buffer mode, buffer start address is UH_TX_DMA
//   0 x:  disable endpoint and disable buffer
//   1 0:  64 bytes buffer for transmittal (OUT endpoint)
//   1 1:  dual 64 bytes buffer by toggle bit bUH_T_TOG selection for transmittal (OUT endpoint), total=128bytes
#define USBHD_UH_EP_RX_EN 0x08    // enable USB host IN endpoint receiving
#define USBHD_UH_EP_RBUF_MOD 0x01 // buffer mode of USB host IN endpoint
// bUH_EP_RX_EN & bUH_EP_RBUF_MOD: USB host IN endpoint buffer mode, buffer start address is UH_RX_DMA
//   0 x:  disable endpoint and disable buffer
//   1 0:  64 bytes buffer for receiving (IN endpoint)
//   1 1:  dual 64 bytes buffer by toggle bit bUH_R_TOG selection for receiving (IN endpoint), total=128bytes

#define USBHD_UH_RX_DMA_OFFSET USBHD_UEPx_DMA_OFFSET(2) // host rx endpoint buffer high address
#define USBHD_UH_TX_DMA_OFFSET USBHD_UEPx_DMA_OFFSET(3) // host tx endpoint buffer high address

#define USBHD_UH_SETUP_OFFSET USBHD_UEPx_TX_CTRL_OFFSET(1)
#define USBHD_UH_PRE_PID_EN 0x0400 // USB host PRE PID enable for low speed device via hub
#define USBHD_UH_SOF_EN 0x04       // USB host automatic SOF enable

#define USBHD_UH_EP_PID_OFFSET USBHD_UEPx_T_LEN_OFFSET(2)
#define USBHD_UH_TOKEN_MASK 0xF0 // bit mask of token PID for USB host transfer
#define USBHD_UH_ENDP_MASK 0x0F  // bit mask of endpoint number for USB host transfer

#define USBHD_UH_RX_CTRL_OFFSET USBHD_UEPx_RX_CTRL_OFFSET(2) // host receiver endpoint control
#define USBHD_UH_R_AUTO_TOG 0x08                             // enable automatic toggle after successful transfer completion: 0=manual toggle, 1=automatic toggle
#define USBHD_UH_R_TOG 0x04                                  // expected data toggle flag of host receiving (IN): 0=DATA0, 1=DATA1
#define USBHD_UH_R_RES 0x01                                  // prepared handshake response type for host receiving (IN): 0=ACK (ready), 1=no response, time out to device, for isochronous transactions

#define USBHD_UH_TX_LEN_OFFSET USBHD_UEPx_T_LEN_OFFSET(3)

#define USBHD_UH_TX_CTRL_OFFSET USBHD_UEPx_TX_CTRL_OFFSET(3) // host transmittal endpoint control
#define USBHD_UH_T_AUTO_TOG 0x08                             // enable automatic toggle after successful transfer completion: 0=manual toggle, 1=automatic toggle
#define USBHD_UH_T_TOG 0x04                                  // prepared data toggle flag of host transmittal (SETUP/OUT): 0=DATA0, 1=DATA1
#define USBHD_UH_T_RES 0x01                                  // expected handshake response type for host transmittal (SETUP/OUT): 0=ACK (ready), 1=no response, time out from device, for isochronous transactions

#endif
