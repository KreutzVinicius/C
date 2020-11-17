#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

struct reg{
	int cod;
	char nome[60];
	float salario;
};
typedef struct reg funcionario;

void mostraMenu();
funcionario * definirTamanho (funcionario *func);
void imprimeTodos(funcionario *func);
void imprimePos(funcionario *func, int pos);
int maiorSalario(funcionario *func);
int menorSalario(funcionario *func);
float mediaSalarios(funcionario *func);
funcionario * inserirFuncionarios(funcionario *func);
funcionario * adicionarFuncionario(funcionario *func);
funcionario * removerFuncionario(funcionario *func);

int tam = 0;

int main(){
	setlocale(LC_ALL, "Portuguese");
    funcionario *func;
	int op,i,tmp;

	do{
		mostraMenu();
		scanf("%d",&op);
		switch(op){
			case 1:
                func = definirTamanho(func);
				break;
			case 2:
				imprimeTodos(func);
				system("pause"); //mensagem que espera o "enter"
				break;
			case 3:
				printf("Qual posicao quer imprimir?\n");
				scanf("%d",tmp);
				imprimePos(func,tmp);
				system("pause");
				break;
			case 4:
				printf("O maior salario esta na posicao %d\n",maiorSalario(func));  
				system("pause");
				break;
			case 5:
				printf("O menor salario esta na posicao %d\n",menorSalario(func));  
				system("pause");
				break;
			case 6:
				printf("A media dos salarios e %.2f\n",mediaSalarios(func));  
				system("pause");
				break;
            case 7:
                func = adicionarFuncionario(func);
                break;
            case 8:
                func = removerFuncionario(func);
                break;
			case 0:
				printf("Obrigado por usar o nosso programa!\n");  
				break;
			default:
				printf("OPCAO NAO CADASTRADA!\n");  
				system("pause");
				break;

		}
	}while(op!=0);
    free (func);
}

void mostraMenu(){
    printf("|------------------------------------|\n");
	printf("|      CADASTRO DE FUNCIONARIOS      |\n");
	printf("|____________________________________|\n");
	printf("|           MENU DE OPCOES           |\n");
	printf("|------------------------------------|\n");
	printf("| 1 - INSERIR VALORES NO VETOR       |\n");
	printf("| 2 - IMPRIMIR TODOS OS FUNCIONARIOS |\n");
	printf("| 3 - IMPRIMIR FUNCIONARIO DA POSICAO|\n");	
	printf("| 4 - RETORNAR POS. DO MAIOR SALARIO |\n");
	printf("| 5 - RETORNAR POS. DO MENOR SALARIO |\n");
	printf("| 6 - RETORNAR A MEDIA DOS SALARIOS  |\n");
    printf("| 7 - INCLUIR FUNCIONÁRIO            |\n");
    printf("| 8 - REMOVER UM FUNCIONÁRIO         |\n");
	printf("| 0 - SAIR                           |\n");
	printf("|------------------------------------|\n");
}
funcionario * definirTamanho (funcionario *func){
    printf("Digite quantos funcionarios deseja criar\n");
    scanf("%d", &tam);

    func= (funcionario *) malloc(tam * sizeof(funcionario));

    func = inserirFuncionarios(func);

	return func;
}

void imprimeTodos(funcionario *func){
	int i;
	for(i=0;i<tam;i++){
		printf("Pos %d:\n",i);
		printf("Codigo: %d\n",func[i].cod);
		printf("Nome: %s\n",func[i].nome);
		printf("Salario: %.2f\n",func[i].salario); //%.2f fara imprimir duas casas decimais depois da virgula
	}
}

void imprimePos(funcionario *func, int pos){
	printf("Pos %i:\n",pos);
	printf("Codigo: %d\n",func[pos].cod);
	printf("Nome: %s\n",func[pos].nome);
	printf("Salario: %.2f\n",func[pos].salario); 
}

int maiorSalario(funcionario *func){
	int i,maior;
	maior=0;
	for(i=0;i<tam;i++){
		if(func[i].salario> func[maior].salario){
			maior=i;
		}
	}
	return(maior);
}

int menorSalario(funcionario *func){
	int i,menor;
	menor=0;
	for(i=0;i<tam;i++){
		if(func[i].salario < func[menor].salario){
			menor=i;
		}
	}
	return(menor);
}

float mediaSalarios(funcionario *func){
	int i;
	float soma;
	soma=0.0;
	for(i=0;i<tam;i++){
		soma+=func[i].salario;
	}
	return(soma/sizeof(func));
}

funcionario * inserirFuncionarios (funcionario *func){
    for(int i=0;i<tam;i++){
        printf("Pos %i:\n",i);
        printf("Digite o codigo:\n");
        scanf("%d",&func[i].cod);
        printf("Digite o nome:\n");
        scanf("%s",&func[i].nome);
        printf("Digite o salario:\n");
        scanf("%f",&func[i].salario);
    }
	return func;
}

funcionario * adicionarFuncionario (funcionario *func){
    tam++;
    func =(funcionario *) realloc(func, tam * sizeof(funcionario));
    
        printf("Digite o codigo:\n");
        scanf("%d",&func[tam -1].cod);
        printf("Digite o nome:\n");
        scanf("%s",&func[tam -1].nome);
        printf("Digite o salario:\n");
        scanf("%f",&func[tam -1].salario);

	return func;
}

funcionario * removerFuncionario (funcionario *func){
int remov;
imprimeTodos(func);

printf("digite a posição do funcionario que deseja remover\n");
scanf("%d", &remov);

// move o funcionario da ultima posição do vetor
func[remov] = func[tam];
// realoca o tamanho do vetor, diminuindo em 1
tam--;
    func = (funcionario *) realloc(func, tam*sizeof(funcionario));
return func;
}