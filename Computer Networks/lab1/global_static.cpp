static unsigned char nbuffered = 0;                           // 缓冲区数据包的数量
static int phl_ready = 0;			              // 物理层是否准备好

/* sender config */
static unsigned char next_frame_to_send = 0;	// 下一次要发送的帧
static unsigned char sender_buffer[MAX_SEQ + 1][PKT_LEN];   // 发送端缓冲区
static unsigned char sender_window_head = 0;				// 发送端窗口左端
static unsigned char sender_window_tail = NR_BUFS - 1;		// 发送端窗口右端

/* receriver config */
static unsigned char frame_expected = 0;					// 希望接收的帧
static unsigned char receiver_buffer[NR_BUFS][PKT_LEN];		// 接收端缓冲区
static unsigned char receiver_window_head = 0;				// 接收端窗口左端
static unsigned char receiver_window_tail = NR_BUFS - 1;    // 接收端窗口右端
static int arrived[NR_BUFS];				// visit 标记数组

static int no_nak = 1;	                                    // 是否发送 NAK