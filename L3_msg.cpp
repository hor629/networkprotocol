#include "mbed.h"
#include "L3_msg.h"

uint8_t L3_encodePARINFO(uint8_t* msg, uint8_t numpar)
{
    uint8_t size;

    msg[0] = 0; //type
    msg[1] = numpar; //������ �� �˸�
    size = 2;

    return size; //������ ���� ����
}

uint8_t L3_getPARINFO_numpar(uint8_t* msg)
{
    return msg[1]; /������ �� �˸�
}


uint8_t L3_encodePARCNF(uint8_t* msg, uint8_t* str)
{
    uint8_t size;

    msg[0] = 2; //type
    strcpy(str, &msg[1]); //Ȯ��ID �˸�
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

    msg[0] = 3; //type
    strcpy(str, &msg[1]); //�� �˸�
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

    msg[0] = 6; //type
    strcpy(str, &msg[1]); //���� ���� �˸�
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

    msg[0] = 8; //type
    msg[1] = subcnf; //�������� Ȯ�� �˸�
    size = 2;

    return size;
}

uint8_t L3_getSUBCNF_subcnf(uint8_t* msg)
{
    return msg[1]; //�������� Ȯ�� �˸�
}


uint8_t L3_encodeRESREQ(uint8_t* msg, uint8_t end, uint8_t* str)
{
    uint8_t size;

    msg[0] = 9; //type
    msg[1] = end; //�������� �˸�
    strcpy(str, &msg[2]);
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




uint8_t L3_decodePARREQ(uint8_t* msg, uint8_t* str1)
// PAR_REQ: ��� ID
{
    uint8_t offset, size;

    if (str1 == NULL)
    {
        debug("[WARNING] null pointer!!! \n");
        return 0;
    }

    msg[0] = 1; //type
    //1�� : ��� ID
    size = msg[1]; //��� ID string ����
    offset = 2; // ������
    strcpy(str1, &msg[offset]); //ù��° data

    return size;
}

uint8_t* L3_getPARREQ_result1(uint8_t* msg)
{
    return &msg[1]; //ù��° data �˸�
}

uint8_t L3_decodeRSCNF(uint8_t* msg, uint8_t* str1, uint8_t* str2, uint8_t* str3)
// RS_CNF: ������ �� Ȯ��, ���� ���� ����, ���� ����
{
    uint8_t offset, size; //offset�� ��ġ(������), size�� ũ�Ⱚ

    if (str1 == NULL || str2 == NULL || str3 == NULL)
    {
        debug("[WARNING] null pointer!!! \n");
        return 0;
    }

    msg[0] = 4; //type
    //1�� : ������ �� Ȯ�� ����
    size = msg[1]; //������ �� Ȯ�� string ����
    offset = 2; // ������
    strcpy(str1, &msg[offset]); //ù��° data

    //2�� : ���� ���� ���� ����
    offset = offset + size + 2;//strlen ���� Ȯ�� �� ����
    size = msg[offset - 1]; //size=len�̶�� �迭�� �ǹ���.
    strcpy(str2, &msg[offset]); //�ι�° data

    //3�� : ���� ����
    offset = offset + size + 2;
    size = msg[offset - 1];
    strcpy(str3, &msg[offset]); //����° data

    
    //size = msg[1 + size + 1]; //strlen ���� Ȯ�� �� ����
    //strcpy(&msg[3], str3); //����° data
    //size = strlen(str1)+ strlen(str2)+ strlen(str3) + 1;

    return size;
}

uint8_t* L3_getRSCNF_result1(uint8_t* msg)
{
    return &msg[1]; //ù��° data �˸�
}

uint8_t* L3_getRSCNF_result2(uint8_t* msg)
{
    return &msg[2]; //�ι�° data �˸�
}

uint8_t* L3_getRSCNF_result3(uint8_t* msg)
{
    return &msg[3]; //����° data �˸�
}


uint8_t L3_decodeRULCNF(uint8_t* msg, uint8_t* str1)
// RUL_CNF: ������ �� Ȯ��
{
    uint8_t offset, size;

    if (str1 == NULL)
    {
        debug("[WARNING] null pointer!!! \n");
        return 0;
    }

    msg[0] = 5; //type
    //1�� : ������ �� Ȯ��
    size = msg[1]; //������ �� Ȯ�� string ����
    offset = 2; // ������
    strcpy(str1, &msg[offset]); //ù��° data

    return size;
}

uint8_t* L3_getRULCNF_result1(uint8_t* msg)
{
    return &msg[1]; //ù��° data �˸�
}

uint8_t L3_decodeESCNF(uint8_t* msg, uint8_t* str1)
// ES_CNF: ������ ���� ����
{
    uint8_t offset, size;

    if (str1 == NULL)
    {
        debug("[WARNING] null pointer!!! \n");
        return 0;
    }

    msg[0] = 7; //type 
    //1�� : ������ ���� ���� ����
    size = msg[1]; //������ ���� ���� string ����
    offset = 2; // ������
    strcpy(str1, &msg[offset]); //ù��° data

    return size;
}

uint8_t* L3_getESCNF_result1(uint8_t* msg)
{
    return &msg[1]; //ù��° data �˸�
}

uint8_t L3_decodeRESCNF(uint8_t* msg, uint8_t* str1)
// RES_CNF: ���� Ȯ��
{
    uint8_t offset, size;

    if (str1 == NULL)
    {
        debug("[WARNING] null pointer!!! \n");
        return 0;
    }

    msg[0] = 10 //type 
    //1�� : ���� Ȯ�� ����
    size = msg[1]; //���� Ȯ�� string ����
    offset = 2; // ������
    strcpy(str1, &msg[offset]); //ù��° data

    return size;
}

uint8_t* L3_getRESCNF_result1(uint8_t* msg)
{
    return &msg[1]; //ù��° data �˸�
}




