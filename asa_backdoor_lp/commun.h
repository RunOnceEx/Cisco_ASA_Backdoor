#ifndef COMMUN_H_INCLUDED
#define COMMUN_H_INCLUDED

#define AUTH_KEY "Wayne_7437"
#define MTU 1500
#define PKT_BUFF_SIZE 1600

#define Linux

#ifdef Windows
#include <windows.h>
#include <winsock2.h>
#endif // Windows

#ifdef Linux
#define SOCKET int
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#endif // Linux

//////////////////////////////////////////////////////////////////////////////////
typedef struct _ETH_Header_
{
    unsigned char DesMAC[6];     //��̫��Ŀ�ĵ�ַ
    unsigned char SrcMAC[6];     //��̫��Դ��ַ
    unsigned short EtherType;    //֡����
} ETH_HEADER;

typedef struct _IP_Header_
{
    unsigned char ip_hl:4;         /*header length(��ͷ���ȣ�*/
    unsigned char ip_v:4;          /*version(�汾)*/
    unsigned char ip_tos;          /*type os service��������*/
    unsigned short int ip_len;     /*total length (�ܳ���)*/
    unsigned short int ip_id;      /*identification (��ʶ��)*/
    unsigned short int ip_off;     /*fragment offset field(����λ��)*/
    unsigned char ip_ttl;          /*time to live (����ʱ��)*/
    unsigned char ip_p;            /*protocol(Э��)*/
    unsigned short int ip_sum;     /*checksum(У���)*/
    unsigned int ip_src;           /*source address(Դ��ַ)*/
    unsigned int ip_dst;           /*destination address(Ŀ�ĵ�ַ)*/
} IP_HEADER;

typedef struct _TCP_Header_
{
    unsigned short int sport;    /*source port (Դ�˿ں�)*/
    unsigned short int dport;    /*destination port(Ŀ�Ķ˿ں�)*/
    unsigned int th_seq;         /*sequence number(�������к�)*/
    unsigned int th_ack;         /*acknowledgement number(ȷ��Ӧ���)*/
    unsigned char th_x:4;        /*unused(δʹ��)*/
    unsigned char th_off:4;      /*data offset(����ƫ����)*/
    unsigned char Flags;         /*��־ȫ*/
    unsigned short int th_win;   /*windows(����)*/
    unsigned short int th_sum;   /*checksum(У���)*/
    unsigned short int th_urp;   /*urgent pointer(����ָ��)*/
} TCP_HEADER;

typedef struct _UDP_Header_
{
    unsigned short int sport;
    unsigned short int dport;
    unsigned short int length;
    unsigned short int checksum;
} UDP_HEADER;

/////////////////////////////////////////////////////////////////////////////////////
SOCKET create_udp_socket();
struct sockaddr_in bind_udp_dest_addr(char *destIP, int destPort);
int send_control_proto_via_udp(SOCKET soc, struct sockaddr_in destAddr, char *destIP, \
                               unsigned short destPort, char *pPayload, unsigned short payloadLen);
int set_redirect_flow();

#endif // COMMUN_H_INCLUDED
