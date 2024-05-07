> s(Network performance parameters) The performance of a client-server system is strongly influenced by two major network characteristics: the bandwidth of the network (that is, how many bits/sec it can transport) and the latency (that is, how many seconds it takes for the first bit to get from the client to the server). Give an example of a network that exhibits high bandwidth but also high latency. Then give an example of one that has both low bandwidth and low latency.
   
1. 高带宽高延迟：卫星网络，带宽通常为 100 Mbps，但延迟一般为 600 ms
2. 低带宽低延迟：蓝牙，例如蓝牙耳机，现代蓝牙耳机基本感觉不到延迟，但带宽通常也很低

>  (Network performance parameters) Besides bandwidth and latency, what other parameter is needed to give a good characterization of the quality of service offered by a network used for (i) digitized voice traffic? (ii) video traffic? (iii) financial transaction traffic?

1. 对于数字音频传输来说，抖动十分关键，抖动是指数据包到达时间的变化率，过高的抖动会导致语音数据包到达时间不一致，从而导致通话中出现断断续续或质量下降的情况
2. 视频传输对于丢包率非常敏感。即使是少量的数据包丢失，也可能导致视频画面出现马赛克，冻结或是质量下降。
3. 对于金融交易来说，网络的可靠性和安全性是至关重要的。金融交易要求高度的数据准确性和完整性，任何数据丢失或篡改都可能导致重大的金融损失和法律问题。

> (Collision of time division system) A disadvantage of a broadcast subnet is the capacity wasted when multiple hosts attempt to access the channel at the same time. As a simplistic example, suppose that time is divided into discrete slots, with each of the n hosts attempting to use the channel with probability p during each slot. What fraction of the slots will be wasted due to collisions?

共有 $n$ 台主机，只要在一个时间槽内有大于等于两台主机同时访问信道就会发生冲突，设一个时间槽内访问信道的主机数量为 $X$，故有：
$$\begin{align*}
    P\{X = 0\} &= (1 - p)^n \\ 
    P\{X = 1\} &= np(1 - p)^{n-1} \\
    P\{X \geq 2\} &= 1 - P\{X = 0\} - P\{X = 1\} \\ &= 1 - (1 - p)^n - np(1 - p)^{n-1}
\end{align*}$$

> What are two reasons for using layered protocols? What is one possible disadvantage of using layered protocols?

1. 简化了设计难度和复杂性，每一层只需要实现特定功能
2. 设计时，每一层不需要关心其他层的具体实现原理。
3. 降低了系统运行效率，对数据的多次封装和解包降低了传输效率

> What is the principle difference between connectionless communication and connection-oriented communication? Give one example of a protocol that uses 1) connectionless communication 2) connection-oriented communication.

1. 无连接通信中，无需确认对端是否存在，发送端可随时发送数据，UDP 协议
2. 面向连接通信中，在通信传输之前，需要先建立专有连接，通过专线传输数据，连接被关闭则无法发送数据， TCP 协议

> Which of the OSI layers and TCP/IP layers handles each of the following: 1) Dividing the transmitted bit stream into frames 2) Determining which route through the subnet to use.

1. OSI: 数据链路层；TCP/IP: 网络接口层
2. OSI: 网络层； TCP/IP: 网际层

> (Encapsulation between 2 layers) If the unit exchanged at the data link level is called a frame and the unit exchanged at the network level is called a packet, do frames encapsulate packets or do packets encapsulate frames? Explain your answer.

由于数据链路层在网络层下面，因此，在数据链路层会处理网络层传来的包，将其封装成帧，而不存在将帧封装成包的情况

> (PDU-header) A system has an n-layer protocol hierarchy. Applications generate messages of length M bytes. At each of the layers, an h-byte header is added. What fraction of the network bandwidth is filled with headers?

PDU 总长度为 nh + M，其中，头部长度为 nh，故头部占比为 $\frac{nh}{nh + M}$

> (Impact of adjacent layers) Suppose there is a change in the service (set of operations) provided by layer k. How does this impact services at layers k-1 and k+1?

第 $k$ 层向第 $k + 1$ 层提供服务，因此，第 $k$ 层服务改变不会影响第 $k - 1$ 层，但第 $k + 1$ 层作为服务的使用者会受到影响