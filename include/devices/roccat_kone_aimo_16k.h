#ifndef ROCCAT_KONE_AIMO_16K_H_
#define ROCCAT_KONE_AIMO_16K_H_

#define USB_VENDOR_ID 0x1e7d // https://usb.org/sites/default/files/vendor_ids051920_0.pdf
#define USB_DEVICE_ID 0x2e2c

#define USBHID_SET_REPORT_REQ 0x09
#define USBHID_SET_REPORT_REQ_TYPE 0x21
#define USBHID_SET_REPORT_REQ_LEN 0x7e
#define USBHID_SET_REPORT_REQ_VAL 0x0306
#define USBHID_SET_REPORT_REQ_INDEX 0x00

#define USBHID_GET_REPORT_REQ 0x01
#define USBHID_GET_REPORT_REQ_TYPE 0xa1
#define USBHID_GET_REPORT_REQ_LEN 0x03
#define USBHID_GET_REPORT_REQ_VAL 0x304

/*
#define USBHID_GET_REPORT_RESP
#define USBHID_GET_REPORT_RESP_TYPE
#define USBHID_GET_REPORT_RESP_LEN 0x03
#define USBHID_GET_REPORT_RESP_VAL
*/

#define ALL_LEDS 0
#define SCROLL_WHEEL_LED 1
#define LEFT_SIDE_TOP_LED 2
#define LEFT_SIDE_MIDDLE_UP_LED 3
#define LEFT_SIDE_MIDDLE_LED 4
#define LEFT_SIDE_MIDDLE_DOWN_LED 5
#define LEFT_SIDE_BOTTOM_LED 6
#define RIGHT_SIDE_TOP_LED 7
#define RIGHT_SIDE_MIDDLE_UP_LED 8
#define RIGHT_SIDE_MIDDLE_LED 9
#define RIGHT_SIDE_MIDDLE_DOWN_LED 10
#define RIGHT_SIDE_BOTTOM_LED 11

#define LED_EFFECT_WAVE
#define LED_EFFECT_SNAKE
#define LED_EFFECT_FULLY_LIT
#define LED_EFFECT_BREATHING2
#define LED_EFFECT_HEATBEAT2

#define LED_EFFECT_SPEED

// typedef struct // uninitialized template payload
// {
//     unsigned char b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15,
//         b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31,
//         b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47,
//         b48, b49, b50, b51, b52, b53, b54, b55, b56, b57, b58, b59, b60, b61, b62, b63,
//         b64, b65, b66, b67, b68, b69, b70, b71, b72, b73, b74, b75, b76, b77, b78, b79,
//         b80, b81, b82, b83, b84, b85, b86, b87, b88, b89, b90, b91, b92, b93, b94, b95,
//         b96, b97, b98, b99, b100, b101, b102, b103, b104, b105, b106, b107, b108, b109, b110, b111,
//         b112, b113, b114, b115, b116, b117, b118, b119, b120, b121, b122, b123, b124, b125;
// } control_payload;

struct LED_CTRL
{
    unsigned char i, r, g, b;
};

// uninitialized illumination control payload
struct ILCP
{
    unsigned char b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15,
        b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31,
        b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47,
        b48, b49, b50, b51, b52, b53, b54, b55, b56, b57, b58, b59, b60;
    struct LED_CTRL LED_CTRL_SCRLW;
    unsigned char b65; // 0x00
    struct LED_CTRL LED_CTRL_LEFT_SIDE_TOP;
    unsigned char b70; // 0x00
    struct LED_CTRL LED_CTRL_LEFT_SIDE_MIDDLE_UP;
    unsigned char b75; // 0x00
    struct LED_CTRL LED_CTRL_LEFT_SIDE_MIDDLE_DOWN;
    unsigned char b80; // 0x00
    struct LED_CTRL LED_CTRL_LEFT_SIDE_BOTTOM;
    unsigned char b85; // 0x00
    struct LED_CTRL LED_CTRL_RIGHT_SIDE_TOP;
    unsigned char b90; // 0x00
    struct LED_CTRL LED_CTRL_RIGHT_SIDE_MIDDLE_UP;
    unsigned char b95; // 0x00
    struct LED_CTRL LED_CTRL_RIGHT_SIDE_MIDDLE_DOWN;
    unsigned char b100; // 0x00
    struct LED_CTRL LED_CTRL_RIGHT_SIDE_BOTTOM;
    unsigned char b105; // 0x00
    struct LED_CTRL LED_CTRL_LEFT_SIDE_MIDDLE;
    unsigned char b110; // 0x00
    struct LED_CTRL LED_CTRL_RIGHT_SIDE_MIDDLE;
    unsigned char b115, b116, b117, b118, b119, b120, b121, b122, b123, b124, b125; // last two bytes probably crc? not utilized yet
};

// initialized with only unknown values from usbhid analysis
struct ILCP ilcp = {
    .b0 = 0x06, .b1 = 0x7e, .b2 = 0x00, .b3 = 0x06, .b4 = 0x04, .b5 = 0x02, .b6 = 0x08, .b7 = 0x00, .b8 = 0x10, .b9 = 0x00, .b10 = 0x18, .b11 = 0x00, .b12 = 0x20, .b13 = 0x00, .b14 = 0x40, .b15 = 0x00, 
    .b16 = 0x08, .b17 = 0x00, .b18 = 0x10, .b19 = 0x00, .b20 = 0x18, .b21 = 0x00, .b22 = 0x20, .b23 = 0x00, .b24 = 0x40, .b25 = 0x00, .b26 = 0x03, .b27 = 0x00, .b28 = 0x00, .b29 = 0x08, .b30 = 0xff, .b31 = 0x07, 
    .b32 = 0x00, .b33 = 0x01, .b34 = 0x05, .b35 = 0x00, .b36 = 0x1d, .b37 = 0x13, .b38 = 0xff, .b39 = 0x00, .b40 = 0xff, .b41 = 0x59, .b42 = 0xff, .b43 = 0x00, .b44 = 0x00, .b45 = 0xff, .b46 = 0xfd, .b47 = 0xfd, 
    .b48 = 0x00, .b49 = 0x00, .b50 = 0xff, .b51 = 0xf4, .b52 = 0x64, .b53 = 0x00, .b54 = 0x00, .b55 = 0xff, .b56 = 0xf4, .b57 = 0x00, .b58 = 0x00, .b59 = 0x00, .b60 = 0xff, .b65 = 0x00, .b70 = 0x00, .b75 = 0x00,
    .b80 = 0x00, .b85 = 0x00, .b90 = 0x00, .b95 = 0x00, 
    .b100 = 0x00, .b105 = 0x00, .b110 = 0x00, .b115 = 0x00, .b116 = 0x01, .b117 = 0x01, .b118 = 0x00, .b119 = 0x00, .b120 = 0x00, .b121 = 0x00, .b122 = 0x00, .b123 = 0x00, .b124 = 0x0e, .b125 = 0x28};

#endif 