/* FRAME kind In datalink.h */
#define FRAME_DATA 1
#define FRAME_ACK  2
#define FRAME_NAK  3

/*  
    DATA Frame
    +=========+========+========+===============+========+
    | KIND(1) | ACK(1) | SEQ(1) | DATA(240~256) | CRC(4) |
    +=========+========+========+===============+========+

    ACK Frame
    +=========+========+========+
    | KIND(1) | ACK(1) | CRC(4) |
    +=========+========+========+

    NAK Frame
    +=========+========+========+
    | KIND(1) | ACK(1) | CRC(4) |
    +=========+========+========+
*/

/* FRAME structure In datalink.c */
struct FRAME {
	unsigned char kind;				// 帧的种类，一字节
	unsigned char ack;   			// ACK 帧的序号，一字节
	unsigned char seq;				// 当前帧的序号，一字节
	unsigned char data[PKT_LEN];	// 数据，长度在240到256字节之间
	unsigned int padding;			// CRC 校验位，四字节
};

