#include "mbed.h"
#include "L3_msg.h"

uint8_t L3_encodePARINFO(uint8_t* msg, uint8_t numpar)
{
    uint8_t size;

    msg[0] = 0; //type
    msg[1] = numpar; //������ �� �˸�
    size = 2;

    return size;
}

uint8_t L3_getPARINFO_cnfID(uint8_t* msg)
{
    return msg[1]; /������ �� �˸�
}


uint8_t L3_encodePARCNF(uint8_t* msg, uint8_t* str)
{
    uint8_t size;

    msg[0] = 0; //type
    strcpy(&msg[1], str); //Ȯ��ID �˸�
    size = strlen(str) + 1;

    return size;
}

uint8_t* L3_getPARCNF_cnfID(uint8_t* msg)
{
    return &msg[1]; //Ȯ��ID �˸�
}


uint8_t L3_encodeRSREQ(uint8_t* msg, uint8_t* str)
{
    uint8_t size;

    msg[0] = 1; //type
    strcpy(&msg[1], str); //�� �˸�
    size = strlen(str) + 1;

    return size;
}

uint8_t* L3_getRSREQ_rule(uint8_t* msg)
{
    return &msg[1]; //�� �˸�
}


uint8_t L3_encodeEXPREQ(uint8_t* msg, uint8_t* str)
{
    uint8_t size;

    msg[0] = 2; //type
    strcpy(&msg[1], str); //���� ����
    size = strlen(str) + 1;

    return size;
}

uint8_t* L3_getEXPREQ_exp(uint8_t* msg)
{
    return &msg[1]; //���� ���� �˸�
}


uint8_t L3_encodeSUBCNF(uint8_t* msg, uint8_t subcnf) //subcnf="���� ���� �Ϸ�"
{
    uint8_t size;

    msg[0] = 2; //type
    msg[1] = subcnf; //�������� Ȯ�� �˸�
    size = 2;

    return size;
}

uint8_t L3_getSUBCNF_end(uint8_t* msg)
{
    return msg[1]; //�������� Ȯ�� �˸�
}


uint8_t L3_encodeRESREQ(uint8_t* msg, uint8_t end, uint8_t* str)
{
    uint8_t size;

    msg[0] = 1; //type
    msg[1] = end; //�������� �˸�
    strcpy(&msg[2], str);
    size = strlen(str) + 2;

    return size;
}

uint8_t L3_getRESREQ_end(uint8_t* msg)
{
    return msg[1]; //�������� �˸�
}

uint8_t* L3_getRESREQ_result(uint8_t* msg)
{
    return &msg[2]; //���Ӱ�� �˸�
}


uint8_t L3_decodeMSGRCVD(uint8_t* msg, uint8_t* str1, uint8_t* str2, uint8_t* str3)
// PAR_REQ: ��� ID
// RS_CNF: ������ �� Ȯ��, ���� ���� ����, ���� ����
// RUL_CNF: ������ �� Ȯ��
// ES_CNF: ������ ���� ����
// RES_CNF: ���� Ȯ��
{
    uint8_t size;

    msg[0] = 1; //type (pcu�� ���ļ�.. �ϴ� type 1��)
    strcpy(&msg[1], str); //ù��° data
    strcpy(&msg[2], str); //�ι�° data
    strcpy(&msg[3], str); //����° data
    size = strlen(str1)+ strlen(str2)+ strlen(str3) + 1;

    return size;
}

uint8_t* L3_getMSGRCVD_result1(uint8_t* msg)
{
    return &msg[1]; //ù��° data �˸�
}

uint8_t* L3_getMSGRCVD_result2(uint8_t* msg)
{
    return &msg[2]; //�ι�° data �˸�
}

uint8_t* L3_getMSGRCVD_result3(uint8_t* msg)
{
    return &msg[3]; //����° data �˸�
}

// ���ڿ� ��� ��� ���� ���ΰ�..? �װ� ���� ����
