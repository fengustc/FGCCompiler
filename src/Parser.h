#ifndef PARSER_H
#define PARSER_H

/**
	@brief ���뵥Ԫ
*/
void translation_unit();

/**
	@brief �����ⲿ����
	@param l �洢���ͣ��ֲ���orȫ�ֵ�
*/
void external_declaration(int l);

/**
	@brief �����������ַ�
	@return �Ƿ��ֺϷ����������ַ�
*/
int type_specifier();

/**
	@brief �����ṹ���ַ�
*/
void struct_specifier();

/**
	@brief �����ṹ��������
*/
void struct_declaration_list();

/**
	@brief �����ṹ����
*/
void struct_declaration();

/**
	@brief ������������
*/
void function_calling_convention(int *fc);

/**
	@brief ���ݽṹ��Ա����
*/
void struct_member_alignment();

/**
	@brief ����������
*/
void declarator();

/**
	@bried ����ֱ��������
*/
void direct_declarator();

/**
	@brief ����ֱ����������׺
*/
void direct_declarator_postfix();

/**
	@brief �����β����ͱ�
	@param func_call ��������Լ��
*/
void parameter_type_list(int func_call);

/**
	@brief �������������
*/
void funcbody();

/**
	@brief ������ֵ��
*/
void initializer();

/**
	@brief �������
	@param bsym
	@param csym
*/
void statement(int * bsym,int *csym);

/**
	@brief �����������
*/
void compound_statement();

/**
	@brief �ж��Ƿ�Ϊ�������ַ�
	@param v ���ʱ��
*/
int is_type_specifier(int v);

/**
	@brief ���ʽ��صĴ���
*/
void expression_statement();

/**
	@brief ѡ�����
*/
void if_statement();

/**
	@brief ѭ�����
*/
void for_statement();

/**
	@brief continue ���
*/
void continue_statement();

/**
	@brief break���
*/
void break_statement();

/**
	@brief return���
*/
void return_statement();

/**
	@brief ���ʽ
*/
void expression();

/**
	@brief ��ֵ���ʽ
*/
void assignment_expression();

/**
	@brief �����ı��ʽ
*/
void equality_expression();

/**
	@brief ��ϵ���ʽ
*/
void relational_expression();

/**
	@brief �ӷ���ı��ʽ
*/
void additive_expression();

/**
	@brief �˳�������ʽ
*/
void multiplicative_expression();

/**
	@brief һԪ���ʽ
*/
void unary_expression();

/**
	@brief sizeof���ʽ
*/
void sizeof_expression();

/**
	@brief ��׺���ʽ
*/
void postfix_expression();

/**
	@brief ��ֵ���ʽ
*/
void primary_expression();

/**
	@brief ʵ�α��ʽ
*/
void argument_expression_list();

/**
	@brief �﷨״̬ö��ֵ
*/
enum e_SynTaxState{
	SNTX_NUL,
	SNTX_SP,
	SNTX_LE_HT,
	SNTX_DELAY
};

/**
	@brief �������ʱȫ�ֵĻ��Ǿֲ���
*/
enum e_Scope
{
	SC_GLOBAL,
	SC_LOCAL
};

/**
	@brief �﷨��������
*/
void syntax_indent();

/**
	@brief ����n��tab��
	@param n ����tab������
*/
void print_Tab(int n);

#endif