#include "usbd_core.h"
#include "usb_ch32_usbhd_reg.h"

#ifndef USBD_IRQHandler
#define USBD_IRQHandler OTG_FS_IRQHandler // use actual usb irq name instead
#endif

#ifndef USB_NUM_BIDIR_ENDPOINTS
#define USB_NUM_BIDIR_ENDPOINTS 8
#endif

/* Endpoint state */
struct usb_dc_ep_state
{
    /** Endpoint max packet size */
    uint16_t ep_mps;
    /** Endpoint Transfer Type.
     * May be Bulk, Interrupt, Control or Isochronous
     */
    uint8_t ep_type;
    uint8_t ep_stalled; /** Endpoint stall flag */
};

/* Driver state */
struct usb_dc_config_priv
{
    volatile uint8_t dev_addr;
    struct usb_dc_ep_state in_ep[USB_NUM_BIDIR_ENDPOINTS];  /*!< IN endpoint parameters*/
    struct usb_dc_ep_state out_ep[USB_NUM_BIDIR_ENDPOINTS]; /*!< OUT endpoint parameters */
} usb_dc_cfg;

/* Endpoint Buffer */
__attribute__((aligned(4))) uint8_t EP0_DatabufHD[64];      // ep0(64)
__attribute__((aligned(4))) uint8_t EP1_DatabufHD[64 + 64]; // ep1_out(64)+ep1_in(64)
__attribute__((aligned(4))) uint8_t EP2_DatabufHD[64 + 64]; // ep2_out(64)+ep2_in(64)
__attribute__((aligned(4))) uint8_t EP3_DatabufHD[64 + 64]; // ep3_out(64)+ep3_in(64)
__attribute__((aligned(4))) uint8_t EP4_DatabufHD[64 + 64]; // ep4_out(64)+ep4_in(64)
__attribute__((aligned(4))) uint8_t EP5_DatabufHD[64 + 64]; // ep5_out(64)+ep5_in(64)
__attribute__((aligned(4))) uint8_t EP6_DatabufHD[64 + 64]; // ep6_out(64)+ep6_in(64)
__attribute__((aligned(4))) uint8_t EP7_DatabufHD[64 + 64]; // ep7_out(64)+ep7_in(64)

void USBD_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

volatile uint8_t mps_over_flag = 0;

__WEAK void usb_dc_low_level_init(void)
{
}

__WEAK void usb_dc_low_level_deinit(void)
{
}

int usb_dc_init(void)
{
    memset(&usb_dc_cfg, 0, sizeof(struct usb_dc_config_priv));

    usb_dc_low_level_init();

    USBHD_DEVICE->BASE_CTRL = 0x00;

    USBHD_DEVICE->UEP4_1_MOD = USBHD_UEP4_RX_EN | USBHD_UEP4_TX_EN | USBHD_UEP1_RX_EN | USBHD_UEP1_TX_EN;
    USBHD_DEVICE->UEP2_3_MOD = USBHD_UEP2_RX_EN | USBHD_UEP2_TX_EN | USBHD_UEP3_RX_EN | USBHD_UEP3_TX_EN;
    USBHD_DEVICE->UEP5_6_MOD = USBHD_UEP5_RX_EN | USBHD_UEP5_TX_EN | USBHD_UEP6_RX_EN | USBHD_UEP6_TX_EN;
    USBHD_DEVICE->UEP7_MOD = USBHD_UEP7_RX_EN | USBHD_UEP7_TX_EN;

    USBHD_DEVICE->UEP0_DMA = (uint32_t)EP0_DatabufHD;
    USBHD_DEVICE->UEP1_DMA = (uint32_t)EP1_DatabufHD;
    USBHD_DEVICE->UEP2_DMA = (uint32_t)EP2_DatabufHD;
    USBHD_DEVICE->UEP3_DMA = (uint32_t)EP3_DatabufHD;
    USBHD_DEVICE->UEP4_DMA = (uint32_t)EP4_DatabufHD;
    USBHD_DEVICE->UEP5_DMA = (uint32_t)EP5_DatabufHD;
    USBHD_DEVICE->UEP6_DMA = (uint32_t)EP6_DatabufHD;
    USBHD_DEVICE->UEP7_DMA = (uint32_t)EP7_DatabufHD;

    USBHD_DEVICE->UEP0_CTRL = USBHD_UEP_R_RES_ACK | USBHD_UEP_T_RES_NAK;
    USBHD_DEVICE->UEP1_CTRL = USBHD_UEP_R_RES_ACK | USBHD_UEP_T_RES_NAK | USBHD_UEP_AUTO_TOG;
    USBHD_DEVICE->UEP2_CTRL = USBHD_UEP_R_RES_ACK | USBHD_UEP_T_RES_NAK | USBHD_UEP_AUTO_TOG;
    USBHD_DEVICE->UEP3_CTRL = USBHD_UEP_R_RES_ACK | USBHD_UEP_T_RES_NAK | USBHD_UEP_AUTO_TOG;
    USBHD_DEVICE->UEP4_CTRL = USBHD_UEP_R_RES_ACK | USBHD_UEP_T_RES_NAK | USBHD_UEP_AUTO_TOG;
    USBHD_DEVICE->UEP5_CTRL = USBHD_UEP_R_RES_ACK | USBHD_UEP_T_RES_NAK | USBHD_UEP_AUTO_TOG;
    USBHD_DEVICE->UEP6_CTRL = USBHD_UEP_R_RES_ACK | USBHD_UEP_T_RES_NAK | USBHD_UEP_AUTO_TOG;
    USBHD_DEVICE->UEP7_CTRL = USBHD_UEP_R_RES_ACK | USBHD_UEP_T_RES_NAK | USBHD_UEP_AUTO_TOG;

    USBHD_DEVICE->UEP1_TX_LEN = 0;
    USBHD_DEVICE->UEP2_TX_LEN = 0;
    USBHD_DEVICE->UEP3_TX_LEN = 0;
    USBHD_DEVICE->UEP4_TX_LEN = 0;
    USBHD_DEVICE->UEP5_TX_LEN = 0;
    USBHD_DEVICE->UEP6_TX_LEN = 0;
    USBHD_DEVICE->UEP7_TX_LEN = 0;

    USBHD_DEVICE->INT_FG = 0xFF;
    USBHD_DEVICE->INT_EN = USBHD_UIE_SUSPEND | USBHD_UIE_BUS_RST | USBHD_UIE_TRANSFER;
    USBHD_DEVICE->DEV_ADDR = 0x00;

    USBHD_DEVICE->BASE_CTRL = USBHD_UC_DEV_PU_EN | USBHD_UC_INT_BUSY | USBHD_UC_DMA_EN;
    USBHD_DEVICE->UDEV_CTRL = USBHD_UD_PD_DIS | USBHD_UD_PORT_EN;
    return 0;
}

int usb_dc_deinit(void)
{
    return 0;
}

int usbd_set_address(const uint8_t addr)
{
    if (addr == 0)
    {
        USBHD_DEVICE->DEV_ADDR = (USBHD_DEVICE->DEV_ADDR & USBHD_UDA_GP_BIT) | 0;
    }
    usb_dc_cfg.dev_addr = addr;
    return 0;
}

int usbd_ep_open(const struct usbd_endpoint_cfg *ep_cfg)
{
    uint8_t ep_idx = USB_EP_GET_IDX(ep_cfg->ep_addr);

    if (USB_EP_DIR_IS_OUT(ep_cfg->ep_addr))
    {
        usb_dc_cfg.out_ep[ep_idx].ep_mps = ep_cfg->ep_mps;
        usb_dc_cfg.out_ep[ep_idx].ep_type = ep_cfg->ep_type;
    }
    else
    {
        usb_dc_cfg.in_ep[ep_idx].ep_mps = ep_cfg->ep_mps;
        usb_dc_cfg.in_ep[ep_idx].ep_type = ep_cfg->ep_type;
    }
    return 0;
}
int usbd_ep_close(const uint8_t ep)
{
    return 0;
}
int usbd_ep_set_stall(const uint8_t ep)
{
    uint8_t ep_idx = USB_EP_GET_IDX(ep);

    if (USB_EP_DIR_IS_OUT(ep))
    {
        switch (ep_idx)
        {
        case 0:
            USBHD_DEVICE->UEP0_CTRL = USBHD_UEP_R_TOG | USBHD_UEP_R_RES_STALL;
            break;
        case 1:
            USBHD_DEVICE->UEP1_CTRL = (USBHD_DEVICE->UEP1_CTRL &= ~USBHD_UEP_R_RES_MASK) | USBHD_UEP_R_RES_STALL;
            break;
        case 2:
            USBHD_DEVICE->UEP2_CTRL = (USBHD_DEVICE->UEP2_CTRL &= ~USBHD_UEP_R_RES_MASK) | USBHD_UEP_R_RES_STALL;
            break;
        case 3:
            USBHD_DEVICE->UEP3_CTRL = (USBHD_DEVICE->UEP3_CTRL &= ~USBHD_UEP_R_RES_MASK) | USBHD_UEP_R_RES_STALL;
            break;
        case 4:
            USBHD_DEVICE->UEP4_CTRL = (USBHD_DEVICE->UEP4_CTRL &= ~USBHD_UEP_R_RES_MASK) | USBHD_UEP_R_RES_STALL;
            break;
        case 5:
            USBHD_DEVICE->UEP5_CTRL = (USBHD_DEVICE->UEP5_CTRL &= ~USBHD_UEP_R_RES_MASK) | USBHD_UEP_R_RES_STALL;
            break;
        case 6:
            USBHD_DEVICE->UEP6_CTRL = (USBHD_DEVICE->UEP6_CTRL &= ~USBHD_UEP_R_RES_MASK) | USBHD_UEP_R_RES_STALL;
            break;
        case 7:
            USBHD_DEVICE->UEP7_CTRL = (USBHD_DEVICE->UEP7_CTRL &= ~USBHD_UEP_R_RES_MASK) | USBHD_UEP_R_RES_STALL;
            break;
        default:
            break;
        }
    }
    else
    {
        switch (ep_idx)
        {
        case 0:
            USBHD_DEVICE->UEP0_CTRL = USBHD_UEP_T_TOG | USBHD_UEP_T_RES_STALL;
            break;
        case 1:
            USBHD_DEVICE->UEP1_CTRL = (USBHD_DEVICE->UEP1_CTRL &= ~USBHD_UEP_T_RES_MASK) | USBHD_UEP_T_RES_STALL;
            break;
        case 2:
            USBHD_DEVICE->UEP2_CTRL = (USBHD_DEVICE->UEP2_CTRL &= ~USBHD_UEP_T_RES_MASK) | USBHD_UEP_T_RES_STALL;
            break;
        case 3:
            USBHD_DEVICE->UEP3_CTRL = (USBHD_DEVICE->UEP3_CTRL &= ~USBHD_UEP_T_RES_MASK) | USBHD_UEP_T_RES_STALL;
            break;
        case 4:
            USBHD_DEVICE->UEP4_CTRL = (USBHD_DEVICE->UEP4_CTRL &= ~USBHD_UEP_T_RES_MASK) | USBHD_UEP_T_RES_STALL;
            break;
        case 5:
            USBHD_DEVICE->UEP5_CTRL = (USBHD_DEVICE->UEP5_CTRL &= ~USBHD_UEP_T_RES_MASK) | USBHD_UEP_T_RES_STALL;
            break;
        case 6:
            USBHD_DEVICE->UEP6_CTRL = (USBHD_DEVICE->UEP6_CTRL &= ~USBHD_UEP_T_RES_MASK) | USBHD_UEP_T_RES_STALL;
            break;
        case 7:
            USBHD_DEVICE->UEP7_CTRL = (USBHD_DEVICE->UEP7_CTRL &= ~USBHD_UEP_T_RES_MASK) | USBHD_UEP_T_RES_STALL;
            break;
        default:
            break;
        }
    }

    return 0;
}

int usbd_ep_clear_stall(const uint8_t ep)
{
    uint8_t ep_idx = USB_EP_GET_IDX(ep);

    if (USB_EP_DIR_IS_OUT(ep))
    {
        switch (ep_idx)
        {
        case 0:

            break;
        case 1:
            USBHD_DEVICE->UEP1_CTRL = (USBHD_DEVICE->UEP1_CTRL & ~(USBHD_UEP_R_TOG | USBHD_UEP_R_RES_MASK)) | USBHD_UEP_R_RES_ACK;
            break;
        case 2:
            USBHD_DEVICE->UEP2_CTRL = (USBHD_DEVICE->UEP2_CTRL & ~(USBHD_UEP_R_TOG | USBHD_UEP_R_RES_MASK)) | USBHD_UEP_R_RES_ACK;
            break;
        case 3:
            USBHD_DEVICE->UEP3_CTRL = (USBHD_DEVICE->UEP3_CTRL & ~(USBHD_UEP_R_TOG | USBHD_UEP_R_RES_MASK)) | USBHD_UEP_R_RES_ACK;
            break;
        case 4:
            USBHD_DEVICE->UEP4_CTRL = (USBHD_DEVICE->UEP4_CTRL & ~(USBHD_UEP_R_TOG | USBHD_UEP_R_RES_MASK)) | USBHD_UEP_R_RES_ACK;
            break;
        case 5:
            USBHD_DEVICE->UEP5_CTRL = (USBHD_DEVICE->UEP5_CTRL & ~(USBHD_UEP_R_TOG | USBHD_UEP_R_RES_MASK)) | USBHD_UEP_R_RES_ACK;
            break;
        case 6:
            USBHD_DEVICE->UEP6_CTRL = (USBHD_DEVICE->UEP6_CTRL & ~(USBHD_UEP_R_TOG | USBHD_UEP_R_RES_MASK)) | USBHD_UEP_R_RES_ACK;
            break;
        case 7:
            USBHD_DEVICE->UEP7_CTRL = (USBHD_DEVICE->UEP7_CTRL & ~(USBHD_UEP_R_TOG | USBHD_UEP_R_RES_MASK)) | USBHD_UEP_R_RES_ACK;
            break;
        default:
            break;
        }
    }
    else
    {
        switch (ep_idx)
        {
        case 0:

            break;
        case 1:
            USBHD_DEVICE->UEP1_CTRL = (USBHD_DEVICE->UEP1_CTRL & ~(USBHD_UEP_T_TOG | USBHD_UEP_T_RES_MASK)) | USBHD_UEP_T_RES_NAK;
            break;
        case 2:
            USBHD_DEVICE->UEP2_CTRL = (USBHD_DEVICE->UEP2_CTRL & ~(USBHD_UEP_T_TOG | USBHD_UEP_T_RES_MASK)) | USBHD_UEP_T_RES_NAK;
            break;
        case 3:
            USBHD_DEVICE->UEP3_CTRL = (USBHD_DEVICE->UEP3_CTRL & ~(USBHD_UEP_T_TOG | USBHD_UEP_T_RES_MASK)) | USBHD_UEP_T_RES_NAK;
            break;
        case 4:
            USBHD_DEVICE->UEP4_CTRL = (USBHD_DEVICE->UEP4_CTRL & ~(USBHD_UEP_T_TOG | USBHD_UEP_T_RES_MASK)) | USBHD_UEP_T_RES_NAK;
            break;
        case 5:
            USBHD_DEVICE->UEP5_CTRL = (USBHD_DEVICE->UEP5_CTRL & ~(USBHD_UEP_T_TOG | USBHD_UEP_T_RES_MASK)) | USBHD_UEP_T_RES_NAK;
            break;
        case 6:
            USBHD_DEVICE->UEP6_CTRL = (USBHD_DEVICE->UEP6_CTRL & ~(USBHD_UEP_T_TOG | USBHD_UEP_T_RES_MASK)) | USBHD_UEP_T_RES_NAK;
            break;
        case 7:
            USBHD_DEVICE->UEP7_CTRL = (USBHD_DEVICE->UEP7_CTRL & ~(USBHD_UEP_T_TOG | USBHD_UEP_T_RES_MASK)) | USBHD_UEP_T_RES_NAK;
            break;
        default:
            break;
        }
    }
    return 0;
}
int usbd_ep_is_stalled(const uint8_t ep, uint8_t *stalled)
{
    return 0;
}

int usbd_ep_write(const uint8_t ep, const uint8_t *data, uint32_t data_len, uint32_t *ret_bytes)
{
    uint8_t ep_idx = USB_EP_GET_IDX(ep);

    if (!data && data_len)
    {
        return -1;
    }

    if (!data_len)
    {
        switch (ep_idx)
        {
        case 0:
            USBHD_DEVICE->UEP0_TX_LEN = 0;
            break;
        case 1:
            USBHD_DEVICE->UEP1_TX_LEN = 0;
            USBHD_DEVICE->UEP1_CTRL = (USBHD_DEVICE->UEP1_CTRL & ~USBHD_UEP_T_RES_MASK) | USBHD_UEP_T_RES_ACK;
            break;
        case 2:
            USBHD_DEVICE->UEP2_TX_LEN = 0;
            USBHD_DEVICE->UEP2_CTRL = (USBHD_DEVICE->UEP2_CTRL & ~USBHD_UEP_T_RES_MASK) | USBHD_UEP_T_RES_ACK;
            break;
        case 3:
            USBHD_DEVICE->UEP3_TX_LEN = 0;
            USBHD_DEVICE->UEP3_CTRL = (USBHD_DEVICE->UEP3_CTRL & ~USBHD_UEP_T_RES_MASK) | USBHD_UEP_T_RES_ACK;
            break;
        case 4:
            USBHD_DEVICE->UEP4_TX_LEN = 0;
            USBHD_DEVICE->UEP4_CTRL = (USBHD_DEVICE->UEP4_CTRL & ~USBHD_UEP_T_RES_MASK) | USBHD_UEP_T_RES_ACK;
            break;
        case 5:
            USBHD_DEVICE->UEP5_TX_LEN = 0;
            USBHD_DEVICE->UEP5_CTRL = (USBHD_DEVICE->UEP5_CTRL & ~USBHD_UEP_T_RES_MASK) | USBHD_UEP_T_RES_ACK;
            break;
        case 6:
            USBHD_DEVICE->UEP6_TX_LEN = 0;
            USBHD_DEVICE->UEP6_CTRL = (USBHD_DEVICE->UEP6_CTRL & ~USBHD_UEP_T_RES_MASK) | USBHD_UEP_T_RES_ACK;
            break;
        case 7:
            USBHD_DEVICE->UEP7_TX_LEN = 0;
            USBHD_DEVICE->UEP7_CTRL = (USBHD_DEVICE->UEP7_CTRL & ~USBHD_UEP_T_RES_MASK) | USBHD_UEP_T_RES_ACK;
            break;
        default:
            break;
        }

        return 0;
    }

    if (data_len > usb_dc_cfg.in_ep[ep_idx].ep_mps)
    {
        data_len = usb_dc_cfg.in_ep[ep_idx].ep_mps;

        if (ep_idx == 0)
        {
            mps_over_flag = 1;
        }
    }

    switch (ep_idx)
    {
    case 0:
        memcpy(&EP0_DatabufHD[0], data, data_len);
        USBHD_DEVICE->UEP0_TX_LEN = data_len;
        break;
    case 1:
        memcpy(&EP1_DatabufHD[64], data, data_len);
        USBHD_DEVICE->UEP1_TX_LEN = data_len;
        USBHD_DEVICE->UEP1_CTRL = (USBHD_DEVICE->UEP1_CTRL & ~USBHD_UEP_T_RES_MASK) | USBHD_UEP_T_RES_ACK;
        break;
    case 2:
        memcpy(&EP2_DatabufHD[64], data, data_len);
        USBHD_DEVICE->UEP2_TX_LEN = data_len;
        USBHD_DEVICE->UEP2_CTRL = (USBHD_DEVICE->UEP2_CTRL & ~USBHD_UEP_T_RES_MASK) | USBHD_UEP_T_RES_ACK;
        break;
    case 3:
        memcpy(&EP3_DatabufHD[64], data, data_len);
        USBHD_DEVICE->UEP3_TX_LEN = data_len;
        USBHD_DEVICE->UEP3_CTRL = (USBHD_DEVICE->UEP3_CTRL & ~USBHD_UEP_T_RES_MASK) | USBHD_UEP_T_RES_ACK;
        break;
    case 4:
        memcpy(&EP4_DatabufHD[64], data, data_len);
        USBHD_DEVICE->UEP4_TX_LEN = data_len;
        USBHD_DEVICE->UEP4_CTRL = (USBHD_DEVICE->UEP4_CTRL & ~USBHD_UEP_T_RES_MASK) | USBHD_UEP_T_RES_ACK;
        break;
    case 5:
        memcpy(&EP5_DatabufHD[64], data, data_len);
        USBHD_DEVICE->UEP5_TX_LEN = data_len;
        USBHD_DEVICE->UEP5_CTRL = (USBHD_DEVICE->UEP5_CTRL & ~USBHD_UEP_T_RES_MASK) | USBHD_UEP_T_RES_ACK;
        break;
    case 6:
        memcpy(&EP6_DatabufHD[64], data, data_len);
        USBHD_DEVICE->UEP6_TX_LEN = data_len;
        USBHD_DEVICE->UEP6_CTRL = (USBHD_DEVICE->UEP6_CTRL & ~USBHD_UEP_T_RES_MASK) | USBHD_UEP_T_RES_ACK;
        break;
    case 7:
        memcpy(&EP7_DatabufHD[64], data, data_len);
        USBHD_DEVICE->UEP7_TX_LEN = data_len;
        USBHD_DEVICE->UEP7_CTRL = (USBHD_DEVICE->UEP7_CTRL & ~USBHD_UEP_T_RES_MASK) | USBHD_UEP_T_RES_ACK;
        break;
    default:
        break;
    }

    if (ret_bytes)
    {
        *ret_bytes = data_len;
    }

    return 0;
}

int usbd_ep_read(const uint8_t ep, uint8_t *data, uint32_t max_data_len, uint32_t *read_bytes)
{
    uint8_t ep_idx = USB_EP_GET_IDX(ep);
    uint32_t read_count;

    if (!data && max_data_len)
    {
        return -1;
    }

    if (!max_data_len)
    {
        return 0;
    }

    read_count = USBHD_DEVICE->RX_LEN;
    read_count = MIN(read_count, max_data_len);

    switch (ep_idx)
    {
    case 0:
        if ((max_data_len == 8) && !read_bytes)
        {
            read_count = 8;
            memcpy(data, &EP0_DatabufHD[0], 8);
        }
        else
        {
            memcpy(data, &EP0_DatabufHD[0], read_count);
        }
        break;
    case 1:
        memcpy(data, &EP1_DatabufHD[0], read_count);
        break;
    case 2:
        memcpy(data, &EP2_DatabufHD[0], read_count);
        break;
    case 3:
        memcpy(data, &EP3_DatabufHD[0], read_count);
        break;
    case 4:
        memcpy(data, &EP4_DatabufHD[0], read_count);
        break;
    case 5:
        memcpy(data, &EP5_DatabufHD[0], read_count);
        break;
    case 6:
        memcpy(data, &EP6_DatabufHD[0], read_count);
        break;
    case 7:
        memcpy(data, &EP7_DatabufHD[0], read_count);
        break;
    default:
        break;
    }

    if (read_bytes)
    {
        *read_bytes = read_count;
    }

    return 0;
}

void USBD_IRQHandler(void)
{
    uint8_t intflag = 0;

    intflag = USBHD_DEVICE->INT_FG;

    if (intflag & USBHD_UIF_TRANSFER)
    {
        switch (USBHD_DEVICE->INT_ST & USBHD_UIS_TOKEN_MASK)
        {
        case USBHD_UIS_TOKEN_SETUP:
            USBHD_DEVICE->UEP0_CTRL = USBHD_UEP_T_TOG | USBHD_UEP_T_RES_NAK | USBHD_UEP_R_TOG | USBHD_UEP_R_RES_ACK;

            usbd_event_notify_handler(USBD_EVENT_SETUP_NOTIFY, NULL);

            USBHD_DEVICE->UEP0_CTRL = USBHD_UEP_T_TOG | USBHD_UEP_T_RES_ACK | USBHD_UEP_R_TOG | USBHD_UEP_R_RES_ACK;
            break;

        case USBHD_UIS_TOKEN_IN:
            switch (USBHD_DEVICE->INT_ST & (USBHD_UIS_TOKEN_MASK | USBHD_UIS_ENDP_MASK))
            {
            case USBHD_UIS_TOKEN_IN:

                usbd_event_notify_handler(USBD_EVENT_EP0_IN_NOTIFY, NULL);
                if (usb_dc_cfg.dev_addr > 0)
                {
                    USBHD_DEVICE->DEV_ADDR = (USBHD_DEVICE->DEV_ADDR & USBHD_UDA_GP_BIT) | usb_dc_cfg.dev_addr;
                    usb_dc_cfg.dev_addr = 0;
                }

                if (mps_over_flag)
                {

                    mps_over_flag = 0;
                    USBHD_DEVICE->UEP0_CTRL ^= USBHD_UEP_T_TOG;
                }
                else
                {
                    USBHD_DEVICE->UEP0_CTRL = USBHD_UEP_T_RES_NAK | USBHD_UEP_R_RES_ACK;
                }
                break;

            case USBHD_UIS_TOKEN_IN | 1:
                USBHD_DEVICE->UEP1_CTRL ^= USBHD_UEP_T_TOG;
                USBHD_DEVICE->UEP1_CTRL = (USBHD_DEVICE->UEP1_CTRL & ~USBHD_UEP_T_RES_MASK) | USBHD_UEP_T_RES_NAK;
                usbd_event_notify_handler(USBD_EVENT_EP_IN_NOTIFY, (void *)(1 | 0x80));
                break;

            case USBHD_UIS_TOKEN_IN | 2:
                USBHD_DEVICE->UEP2_CTRL ^= USBHD_UEP_T_TOG;
                USBHD_DEVICE->UEP2_CTRL = (USBHD_DEVICE->UEP2_CTRL & ~USBHD_UEP_T_RES_MASK) | USBHD_UEP_T_RES_NAK;
                usbd_event_notify_handler(USBD_EVENT_EP_IN_NOTIFY, (void *)(2 | 0x80));
                break;

            case USBHD_UIS_TOKEN_IN | 3:
                USBHD_DEVICE->UEP3_CTRL ^= USBHD_UEP_T_TOG;
                USBHD_DEVICE->UEP3_CTRL = (USBHD_DEVICE->UEP3_CTRL & ~USBHD_UEP_T_RES_MASK) | USBHD_UEP_T_RES_NAK;
                usbd_event_notify_handler(USBD_EVENT_EP_IN_NOTIFY, (void *)(3 | 0x80));
                break;

            case USBHD_UIS_TOKEN_IN | 4:
                USBHD_DEVICE->UEP4_CTRL ^= USBHD_UEP_T_TOG;
                USBHD_DEVICE->UEP4_CTRL = (USBHD_DEVICE->UEP4_CTRL & ~USBHD_UEP_T_RES_MASK) | USBHD_UEP_T_RES_NAK;
                usbd_event_notify_handler(USBD_EVENT_EP_IN_NOTIFY, (void *)(4 | 0x80));
                break;

            case USBHD_UIS_TOKEN_IN | 5:
                USBHD_DEVICE->UEP5_CTRL ^= USBHD_UEP_T_TOG;
                USBHD_DEVICE->UEP5_CTRL = (USBHD_DEVICE->UEP5_CTRL & ~USBHD_UEP_T_RES_MASK) | USBHD_UEP_T_RES_NAK;
                usbd_event_notify_handler(USBD_EVENT_EP_IN_NOTIFY, (void *)(5 | 0x80));
                break;

            case USBHD_UIS_TOKEN_IN | 6:
                USBHD_DEVICE->UEP6_CTRL ^= USBHD_UEP_T_TOG;
                USBHD_DEVICE->UEP6_CTRL = (USBHD_DEVICE->UEP6_CTRL & ~USBHD_UEP_T_RES_MASK) | USBHD_UEP_T_RES_NAK;
                usbd_event_notify_handler(USBD_EVENT_EP_IN_NOTIFY, (void *)(6 | 0x80));
                break;

            case USBHD_UIS_TOKEN_IN | 7:
                USBHD_DEVICE->UEP7_CTRL ^= USBHD_UEP_T_TOG;
                USBHD_DEVICE->UEP7_CTRL = (USBHD_DEVICE->UEP7_CTRL & ~USBHD_UEP_T_RES_MASK) | USBHD_UEP_T_RES_NAK;
                usbd_event_notify_handler(USBD_EVENT_EP_IN_NOTIFY, (void *)(7 | 0x80));
                break;

            default:
                break;
            }
            break;

        case USBHD_UIS_TOKEN_OUT:
            switch (USBHD_DEVICE->INT_ST & (USBHD_UIS_TOKEN_MASK | USBHD_UIS_ENDP_MASK))
            {
            case USBHD_UIS_TOKEN_OUT:
                usbd_event_notify_handler(USBD_EVENT_EP0_OUT_NOTIFY, NULL);
                break;

            case USBHD_UIS_TOKEN_OUT | 1:
                if (USBHD_DEVICE->INT_ST & USBHD_UIS_TOG_OK)
                {
                    USBHD_DEVICE->UEP1_CTRL ^= USBHD_UEP_R_TOG;
                    usbd_event_notify_handler(USBD_EVENT_EP_OUT_NOTIFY, (void *)(1 & 0x7f));
                }
                break;

            case USBHD_UIS_TOKEN_OUT | 2:
                if (USBHD_DEVICE->INT_ST & USBHD_UIS_TOG_OK)
                {
                    USBHD_DEVICE->UEP2_CTRL ^= USBHD_UEP_R_TOG;
                    usbd_event_notify_handler(USBD_EVENT_EP_OUT_NOTIFY, (void *)(2 & 0x7f));
                }
                break;

            case USBHD_UIS_TOKEN_OUT | 3:
                if (USBHD_DEVICE->INT_ST & USBHD_UIS_TOG_OK)
                {
                    USBHD_DEVICE->UEP3_CTRL ^= USBHD_UEP_R_TOG;
                    usbd_event_notify_handler(USBD_EVENT_EP_OUT_NOTIFY, (void *)(3 & 0x7f));
                }
                break;

            case USBHD_UIS_TOKEN_OUT | 4:
                if (USBHD_DEVICE->INT_ST & USBHD_UIS_TOG_OK)
                {
                    USBHD_DEVICE->UEP4_CTRL ^= USBHD_UEP_R_TOG;
                    usbd_event_notify_handler(USBD_EVENT_EP_OUT_NOTIFY, (void *)(4 & 0x7f));
                }
                break;

            case USBHD_UIS_TOKEN_OUT | 5:
                if (USBHD_DEVICE->INT_ST & USBHD_UIS_TOG_OK)
                {
                    USBHD_DEVICE->UEP5_CTRL ^= USBHD_UEP_R_TOG;
                    usbd_event_notify_handler(USBD_EVENT_EP_OUT_NOTIFY, (void *)(5 & 0x7f));
                }
                break;

            case USBHD_UIS_TOKEN_OUT | 6:
                if (USBHD_DEVICE->INT_ST & USBHD_UIS_TOG_OK)
                {
                    USBHD_DEVICE->UEP6_CTRL ^= USBHD_UEP_R_TOG;
                    usbd_event_notify_handler(USBD_EVENT_EP_OUT_NOTIFY, (void *)(6 & 0x7f));
                }
                break;

            case USBHD_UIS_TOKEN_OUT | 7:
                if (USBHD_DEVICE->INT_ST & USBHD_UIS_TOG_OK)
                {
                    USBHD_DEVICE->UEP7_CTRL ^= USBHD_UEP_R_TOG;
                    usbd_event_notify_handler(USBD_EVENT_EP_OUT_NOTIFY, (void *)(7 & 0x7f));
                }
                break;
            }

            break;

        case USBHD_UIS_TOKEN_SOF:

            break;

        default:
            break;
        }

        USBHD_DEVICE->INT_FG = USBHD_UIF_TRANSFER;
    }
    else if (intflag & USBHD_UIF_BUS_RST)
    {
        USBHD_DEVICE->DEV_ADDR = 0;

        USBHD_DEVICE->UEP0_CTRL = USBHD_UEP_R_RES_ACK | USBHD_UEP_T_RES_NAK;
        USBHD_DEVICE->UEP1_CTRL = USBHD_UEP_R_RES_ACK | USBHD_UEP_T_RES_NAK;
        USBHD_DEVICE->UEP2_CTRL = USBHD_UEP_R_RES_ACK | USBHD_UEP_T_RES_NAK;
        USBHD_DEVICE->UEP3_CTRL = USBHD_UEP_R_RES_ACK | USBHD_UEP_T_RES_NAK;
        USBHD_DEVICE->UEP4_CTRL = USBHD_UEP_R_RES_ACK | USBHD_UEP_T_RES_NAK;
        USBHD_DEVICE->UEP5_CTRL = USBHD_UEP_R_RES_ACK | USBHD_UEP_T_RES_NAK;
        USBHD_DEVICE->UEP6_CTRL = USBHD_UEP_R_RES_ACK | USBHD_UEP_T_RES_NAK;
        USBHD_DEVICE->UEP7_CTRL = USBHD_UEP_R_RES_ACK | USBHD_UEP_T_RES_NAK;

        usbd_event_notify_handler(USBD_EVENT_RESET, NULL);

        USBHD_DEVICE->INT_FG |= USBHD_UIF_BUS_RST;
    }
    else if (intflag & USBHD_UIF_SUSPEND)
    {
        if (USBHD_DEVICE->MIS_ST & USBHD_UMS_SUSPEND)
        {
            ;
        }
        else
        {
            ;
        }
        USBHD_DEVICE->INT_FG = USBHD_UIF_SUSPEND;
    }
    else
    {
        USBHD_DEVICE->INT_FG = intflag;
    }
}
