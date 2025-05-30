#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 5

typedef struct{
	float enade, idd, doutores, mestres, regtrabalho, orgdiped, infra, oport;
}Scpc;

typedef struct{
	int codigo, alunos;
	Scpc insumos;
	float cpc_continuo;
	int cpc_faixa;
}Scurso;

int lerArq (Scurso curso[], char nomearq[], int *linhas);
void calculo (Scurso curso[], int linhas);
int faixa (float num);
float indicegeral(int linhas, Scurso curso[]);
void exibir (int linhas, Scurso curso[]);
int adicionarTXT (int linhas, Scurso curso[], char nomearq[]);
void adicionar (int *linhas, Scurso curso[], char nomearq[]);

int main(){
	Scurso curso[MAX];
	int opcao, linhas=0, resp;
	do{
		printf("Conceito Preliminar de Curso (CPC)");
		printf("\n\n1 - inclusao de novo(s) curso(s)");
		printf("\n2 - processar dados");
		printf("\n3 - sair");
		
		printf("\n\nopcao: ");
		scanf("%d", &opcao);
		printf("\n--------------------------------\n");
		
		resp=lerArq(curso, "cursos.txt", &linhas);
		
		switch(opcao){
			case 1:
				if(resp<0){
					printf("Erro ao ler o arquivo. ");
				} else if(resp==0) {
					printf("Quantidade maxima de cursos. ");
				} else{
					adicionar(&linhas, curso, "cursos.txt");
				}
				break;
			case 2:
				if(linhas<=0){
					printf("Nao ha cursos. ");
				} else if(resp<0){
					printf("Erro ao ler o arquivo. ");
				} else {
					exibir(linhas, curso);
				}
				break;
			case 3:
				printf("Finalizando o programa...");
				break;
			default:
				printf("opcao invalida.");
		}
		
		system("pause");
		system("cls");
	}while(opcao!=3);
	return 0;
}

int lerArq (Scurso curso[], char nomearq[], int *linhas){
	FILE *arq;
	
	arq=fopen(nomearq, "r");
	if(!arq){
		fclose(arq);
		return -1;
	}
	*linhas=0;
	while(fscanf(arq, "%d|%f|%f|%f|%f|%f|%f|%f|%f|%d", &curso[*linhas].codigo, 
	                                                   &curso[*linhas].insumos.enade, 
	                                                   &curso[*linhas].insumos.idd, 
                                                       &curso[*linhas].insumos.doutores, 
                                                       &curso[*linhas].insumos.mestres, 
                                                       &curso[*linhas].insumos.regtrabalho, 
                                                       &curso[*linhas].insumos.orgdiped, 
                                                       &curso[*linhas].insumos.infra, 
                                                       &curso[*linhas].insumos.oport, 
                                                       &curso[*linhas].alunos) !=EOF){
		if((*linhas)>=MAX){
			fclose(arq);
			return 0; 
		}
		calculo(curso, *linhas); 
		(*linhas)++;
	}
	
	fclose(arq);
	return 1;
}

void calculo (Scurso curso[], int i){
	curso[i].cpc_continuo = (curso[i].insumos.enade * 0.2)+
	                        (curso[i].insumos.idd * 0.35)+
	                        (curso[i].insumos.doutores * 0.15)+
	                        (curso[i].insumos.mestres * 0.075)+
                        	(curso[i].insumos.regtrabalho * 0.075)+
                        	(curso[i].insumos.orgdiped * 0.075)+
                        	(curso[i].insumos.infra * 0.05)+
                        	(curso[i].insumos.oport * 0.025);
                        	
	curso[i].cpc_faixa=faixa(curso[i].cpc_continuo);
}

int faixa (float num){
	if(num<0.945){
		return 1;
	} else if(num<1.945){
		return 2;
	} else if(num<2.945){
	     return 3;
	} else if(num<3.945){
		return 4;
    } else{
    	return 5;
	}
}

void exibir (int linhas, Scurso curso[]){
	int i, j;
	float IGC;
	printf("> CURSOS");
	for(i=0;i<linhas;i++){
		printf("\nCURSO %d", i+1);
		printf("\ncodigo: %d", curso[i].codigo);
		printf("\nCPC continuo: %.2f", curso[i].cpc_continuo);
		printf("\nCPC faixa: %d", curso[i].cpc_faixa);
		printf("\nclassificacao: %s", curso[i].cpc_faixa<3? "insatisfatorio":"satisfatorio");
		printf("\n\n");
	}
	printf("\n>conceito preliminar de curso(CPC) faixa");
	for(j=1;j<=5;j++){
		printf("\n CPC faixa %d: ", j);
		for(i=0;i<linhas;i++){
			if(curso[i].cpc_faixa==j){
				printf("%d ", curso[i].codigo);
			}
		}
	}
	
	IGC=indicegeral(linhas, curso);
	printf("\n\n\nIGC Continuo: %.2f", IGC);
	printf("\nIGC: %d\n\n", faixa(IGC));
}

float indicegeral(int linhas, Scurso curso[]){
	int i, divisor=0;
	float soma=0;
	for(i=0;i<linhas;i++){
		soma+=(curso[i].cpc_continuo*curso[i].alunos);
		divisor+=curso[i].alunos;
	}
	if(soma==0 || divisor==0){
		return 0;
	} else{
		return soma/divisor;
	}
}

int adicionarTXT (int linhas, Scurso curso[], char nomearq[]){
	FILE *arq;
	
	arq=fopen(nomearq, "a");
	if(!arq){
		return -1;
	}
	
	fprintf(arq, "%d|%.2f|%.2f|%.2f|%.2f|%.2f|%.2f|%.2f|%.2f|%d\n", curso[linhas].codigo, 
	                                                                curso[linhas].insumos.enade, 
	                                                                curso[linhas].insumos.idd, 
                                                                	curso[linhas].insumos.doutores, 
                                                                	curso[linhas].insumos.mestres, 
                                                                	curso[linhas].insumos.regtrabalho, 
                                                                	curso[linhas].insumos.orgdiped, 
                                                                	curso[linhas].insumos.infra, 
                                                                	curso[linhas].insumos.oport, 
                                                                	curso[linhas].alunos);
	
	fclose(arq);
	return 1;
}

void adicionar (int *linhas, Scurso curso[], char nomearq[]){
	if(*linhas>=MAX){
	printf("Quantidade maxima de cursos.");
	return;	
	}
	
	printf("\ncodigo do curso: ");
	scanf("%d",&curso[*linhas].codigo);
	
	printf("\nNota ENADE: ");
	scanf("%f",&curso[*linhas].insumos.enade);
	
	printf("\nIDD: ");
	scanf("%f",&curso[*linhas].insumos.idd);
	
	printf("\nDoutores: ");
	scanf("%f",&curso[*linhas].insumos.doutores);
	
	printf("\nMestres: ");
	scanf("%f",&curso[*linhas].insumos.mestres);
	
	printf("\nRegime de Trabalho: ");
	scanf("%f",&curso[*linhas].insumos.regtrabalho);
	
	printf("\nOrganizacao Didatico-pedagogica: ");
	scanf("%f",&curso[*linhas].insumos.orgdiped);
	
	printf("\nInfraestrutura: ");
	scanf("%f",&curso[*linhas].insumos.infra);
	
	printf("\nOportunidades de Ampliacao Academica e Profissional: ");
	scanf("%f",&curso[*linhas].insumos.oport);
	
	printf("\nalunos: ");
	scanf("%d",&curso[*linhas].alunos);
	
	if (adicionarTXT(*linhas, curso, nomearq)<0){
		printf("\n\nErro ao adicionar o curso. ");
	} else{
		printf("\n\nCurso adicionado com sucesso! ");
	}
	
	(*linhas)++;
}
