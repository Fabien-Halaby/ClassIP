#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Addresse
{
	unsigned int a;
	unsigned int b;
	unsigned int c;
	unsigned int d;
};

void header(char *type);
void start(char *title);
void end();
void style();
struct Addresse saisir(struct Addresse identification);
char *classe(struct Addresse identifiant);
void principale();

int main()
{
    principale();

    return 0;
}

void principale()
{
    struct Addresse identification;

    header("text/html\n\n");
    start("Classe d'addresse IP");
    
    identification = saisir(identification);

    printf("<table>");
        printf("<tr><td>Addresse</td> <td>Classe</td></tr>");
        printf("<tr><td>%d.%d.%d.%d</td> <td>%s</td></tr>",identification.a,identification.b,identification.c,identification.d,classe(identification));
    printf("</table>");
    printf("<a href=\"http://localhost/ADDRESSE/classe_web.html\">Revenir</a>");

    end();
}

void header(char *type)
{
	printf("Content-Type:%s\n\n",type);
}
void start(char *title)
{
	printf("<!DOCTYPE>\n");
	printf("<html>\n");
	printf("<head>\n");
	printf("<title>%s</title>\n",title);
	printf("<meta charset=\"UTF-8\">\n");
	printf("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n");
    style();
	printf("</head>\n");
	printf("<body>\n");
}
void end()
{
	printf("</body>\n");
	printf("</html>");
}
void style()
{
    printf("<style>");
    printf("*{");
        printf("padding: 0;margin: 0;box-sizing: border-box;");
    printf("}");

    printf("body{");
        printf("height: 100vh;background-color: #000;display: flex;flex-direction: column;align-items: center;justify-content: center;");
    printf("}");

    printf("table{");
        printf("padding: 50px 50px;border: 1px solid #fff;");
    printf("}");

    printf("tr,td{");
        printf("border: 1px solid #fff;padding: 10px 10px;color: #fff;text-align: center;text-transform: uppercase;font-size: 20px;fon-weight: 500;");
    printf("}");

    printf("a{");
        printf("transition: 0.5s ease-out;padding: 10px 10px;border: 1px solid #fff;color: #fff;text-transform: uppercase;text-decoration: none;margin-top: 50px;");
    printf("}");

    printf("a:hover{");
        printf("background-color: #fff;color: #000;");
    printf("}");
    printf("</style>");
}
struct Addresse saisir(struct Addresse identification)
{
    char *qptr;
	char *buffer;
	char *token;
    char *addresse;

    buffer = (char *)malloc(200*sizeof(char));
    addresse = (char *)malloc(20*sizeof(char));
    
    qptr = getenv("QUERY_STRING");
    if(qptr == NULL)
    {
        printf("<p>Une erreur se produite.</p>");
        exit(EXIT_FAILURE);
    }
    strncpy(buffer,qptr,200);

    token = strtok(buffer,"&");
    sscanf(token,"addresse=%s",addresse);

    if(sscanf(addresse,"%d.%d.%d.%d",&identification.a,&identification.b,&identification.c,&identification.d) != 4)
    {
        printf("<p>Addresse non valable.</p>");
        exit(EXIT_FAILURE);
    }

    
    free(buffer);
    free(addresse);

    return identification;
}

char *classe(struct Addresse identifiant)
{
	identifiant = saisir(identifiant);
	
	if(identifiant.a < 128  && identifiant.b <= 255 && identifiant.c <= 255 && identifiant.d <= 255)
	{
		return "<p>CLASSE A</p>";
	}
	else if(identifiant.a >= 128 && identifiant.a < 192 && identifiant.b <= 255 && identifiant.c <= 255 && identifiant.d <= 255)
	{
		return "<p>CLASSE B</p>";
	}
	else if(identifiant.a >= 192 && identifiant.a < 224 && identifiant.b <= 255 && identifiant.c <= 255 && identifiant.d <= 255)
	{
		return "<p>CLASSE C</p>";
	}
	else if(identifiant.a >= 224 && identifiant.a < 240 && identifiant.b <= 255 && identifiant.c <= 255 && identifiant.d <= 255)
	{
		return "<p>CLASSE D</p>";
	}
	else if(identifiant.a >= 240 && identifiant.a <= 255 && identifiant.b <= 255 && identifiant.c <= 255 && identifiant.d <= 255)
	{
		return "<p>CLASSE E</p>";
	}
	else
	{
		return "<p>Adresse non valable</p>";
	}
}