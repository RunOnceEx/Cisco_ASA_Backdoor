#ifndef PROTOCOL_H_INCLUDED
#define PROTOCOL_H_INCLUDED

enum _protocol_type_
{
    PROTO_CONTROL = 1,      //�Ժ��ŵĿ�������
    PROTO_REPO_STAT,        //���ص�����ִ��״̬
    PROTO_FRAG,             //һ���Ƭ����
};
typedef struct _Protocol_Header_
{
    char key[20];                   //ͨѶKEY
    unsigned char type;             //�ϲ�Э������
    unsigned short payload_len;     //Я���غɳ���
}PROTO_HDR;

//////////////////////////////////////////////////////////////////////////////////////////
enum _fragment_protocol_type_
{
    FRAG_PROTO_OPER_MEM = 1,
    FRAG_PROTO_REDIR_FLOW,
};
typedef struct _Packet_Fragment_Header_
{
    unsigned char type;             //�ϲ�Э������
    unsigned int sequence;          //�����Ƭ�������к�
    unsigned short id;              //��ǰ��Ƭ����ID
    unsigned char fin_flag;         //��Ƭ������ʶ
    unsigned short payload_len;     //Я���غɳ���
}PKT_FRAG_HDR;

//////////////////////////////////////////////////////////////////////////////////////////
typedef struct _Redirect_Flow_Header_
{
    unsigned int sequence;          //��ǰ�ض��������к�
    unsigned short payload_len;     //Я���غɳ���
}REDIR_HDR;

//////////////////////////////////////////////////////////////////////////////////////////
enum _send_via_protocol_
{
    USE_IP = 1,
    USE_UDP,
    USE_TCP,
};
enum _cap_protocol_type_
{
    CAP_PROTO_IP = 1,
    CAP_PROTO_TCP,
    CAP_PROTO_UDP,
};
typedef struct _Capture_Rule_
{
    unsigned int id;

    unsigned char proto;
    unsigned int src_ip;
    unsigned int src_mask;
    unsigned short src_port;
    unsigned int dest_ip;
    unsigned int dest_mask;
    unsigned short dest_port;

    unsigned char send_proto;   //�����ض�������ʹ�õ�Э�顣0:ip   1:udp
    unsigned int send_dest_ip;
    unsigned short send_dest_port;
    unsigned int send_src_ip;
    unsigned short send_src_port;
}CAP_RULE;

//////////////////////////////////////////////////////////////////////////////////////////
typedef struct _Operation_Memory_Header_
{
    int address;
    int size;
    unsigned short payload_len;
}OPER_MEM_HDR;

//////////////////////////////////////////////////////////////////////////////////////////
enum _control_type_
{
    CONTROL_FETCH_STATUS = 1,   //��ȡ����ֲ��״̬
    CONTROL_SET_REDIR_RULE,     //���������ض������
    CONTROL_FETCH_REDIR_RULE,   //��ȡ�����õ��ض������
    CONTROL_DEL_REDIR_RULE,     //ɾ���ض������
    CONTROL_ALLOC_MEM,          //�����ڴ�
    CONTROL_FREE_MEM,           //�ͷ��ڴ�
    CONTROL_RD_MEM,             //��ȡ�ڴ�
    CONTROL_WR_MEM,             //д�ڴ�
    CONTROL_DIS_AUTH,           //ȡ����֤
    CONTROL_EN_AUTH,            //������֤
    CONTROL_CALL_ADDR,          //���õ�ַ
};
typedef struct _Control_Command_
{
    unsigned char type;         //������������
    union
    {
        CAP_RULE capture_rule;       //�����ض������
        OPER_MEM_HDR operate_mem;    //�ڴ��������
    };
}CONTROL_CMD;

//////////////////////////////////////////////////////////////////////////////////////////
typedef struct _Report_Status_
{
    unsigned char type;     //��������
    int status_code;        //״̬��
    char msg[20];
}REPO_STAT;

#endif // PROTOCOL_H_INCLUDED
