#include"Parser.h"
#include"GlobalVar.h"
#include<stdio.h>

/**
	@brief ���뵥Ԫ
*/
void translation_unit(){

	while(token != TK_EOF){
		external_declaration(SC_GLOBAL);
	}
}

/**
	@brief �����ⲿ����
	@param l �洢���ͣ��ֲ���orȫ�ֵ�
*/
void external_declaration(int l){
	if(!type_specifier()){
		expect("<�������ַ�>");
	}
	if(token == TK_SEMICOLON){
		get_token();
		return;
	}
	while(1){
		declarator();
		if(token == TK_BEGIN){
			if(l == SC_LOCAL){
				error("��֧�ֺ���Ƕ�׶���");
			}
			funcbody();
			break;
		}else{
			if(token == TK_ASSIGN){
				get_token();
				initializer();
			}
			if(token == TK_COMMA){
				get_token();
			}else{
				syntax_state = SNTX_LE_HT;
				skip(TK_SEMICOLON);
				break;
			}
		}
	}
}

/**
	@brief �����������ַ�
	@return �Ƿ��ֺϷ����������ַ�
*/
int type_specifier(){
	int type_found = 0;
	switch (token)
	{
	case KW_CHAR:
		/*type_found = 1;
		syntax_state = SNTX_SP;
		get_token();
		break;*/
	case KW_CHORT:
		/*type_found = 1;
		syntax_state = SNTX_SP;
		get_token();
		break;*/
	case KW_VOID:
		/*type_found = 1;
		syntax_state = SNTX_SP;
		get_token();
		break;*/
	case KW_INT:
		type_found = 1;
		syntax_state = SNTX_SP;
		get_token();
		break;
	case KW_STRUCT:
		syntax_state = SNTX_SP;
		struct_specifier();
		type_found = 1;
		break;
	default:
		break;
	}
	return type_found;
}

/**
	@brief �����ṹ���ַ�
*/
void struct_specifier(){
	
}

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
	@brief �﷨��������
*/
void syntax_indent(){
	switch (syntax_state)
	{
	case SNTX_NUL:
		color_token(LEX_NORMAL);
		break;
	case SNTX_SP:
		printf(" ");
		color_token(LEX_NORMAL);
		break;
	case SNTX_LE_HT:
		{
			if(token == TK_END)
				syntax_level -- ;
			printf("\n");
			print_Tab(syntax_level);
		}
		color_token(LEX_NORMAL);
		break;
	case SNTX_DELAY:
		break;
	default:
		break;
	}
	syntax_state = SNTX_NUL;
}

/**
	@brief ����n��tab��
	@param n ����tab������
*/
void print_Tab(int n){
	int i = 0;
	for(;i<n;i++){
		printf("\t");
	}
}