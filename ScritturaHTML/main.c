#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRLEN 100
#define MAX_FILENAME 255

FILE* baseHTML(FILE* paginaHTML, char nomeFile[]);
FILE* fineHTML(FILE* paginaHTML, char nomeFile[]);

FILE* baseJavascript(FILE* javascript, char nomeFile[]);

FILE* inserisciNome(FILE* javascript, char nomeFile[], char nome[]);
FILE* inserisciRuolo(FILE* javascript, char nomeFile[], char ruolo[], int i);
FILE* inserisciDivisione(FILE* javascript, char nomeFile[]);

FILE* implementaDati(FILE* paginaHTML, char nomePagina[], FILE* javascript, char nomeDati[], int i);

int controlloFileStringa(char nomeFile[], char ruolo[]);

int main(int argc, char** argv) {

    char file[MAX_FILENAME + 1];
    char nome[MAX_STRLEN + 1];
    char ruoloEsaminato[MAX_STRLEN + 1];
    char nuovoRuolo[MAX_STRLEN + 1];
    char nuovoNome[MAX_STRLEN + 1];
    
    FILE *fileInput;
    FILE *paginaHTML;
    FILE *javascript;
    
    int i=0;
    
    printf("Inserisci il nome del file: ");
    scanf("%[^\n]s", file);                     

    fileInput = fopen(file, "r");
    if (fileInput == NULL) {
        printf("Impossibile aprire il file.");
    } else {
        baseHTML(paginaHTML, "ruoli.html");    
        baseJavascript(javascript, "dati.js");
        fscanf(fileInput, "%[^-]-%s", nome, ruoloEsaminato);   
        
        while (!feof(fileInput)) {
            if (controlloFileStringa("dati.js", ruoloEsaminato)==0){
                i++;
                inserisciRuolo(javascript, "dati.js", ruoloEsaminato, i);       
                inserisciNome(javascript, "dati.js", nome);                  
                
                while (!feof(fileInput)) {                                      
                    fscanf(fileInput, "\n%[^-]-%s", nuovoNome, nuovoRuolo);          
                    if (strcmp(nuovoRuolo,ruoloEsaminato)==0 && strcmp(nuovoNome,nome)!=0){    
                        inserisciDivisione(javascript, "dati.js");
                        inserisciNome(javascript, "dati.js", nuovoNome);         
                    }
                }
                fclose(fileInput);
                implementaDati(paginaHTML, "ruoli.html", javascript, "dati.js", i);
                fileInput = fopen(file, "r");
            }
                fscanf(fileInput, "\n%[^-]-%s", nome, ruoloEsaminato);
            }
            
        fclose(fileInput);
        fineHTML(paginaHTML, "ruoli.html");
    }
    return (EXIT_SUCCESS);
}

FILE* baseHTML(FILE* paginaHTML, char nomeFile[]) {     
    
    paginaHTML = fopen(nomeFile, "w");
    if (paginaHTML == NULL) {
        printf("Impossibile aprire la pagina.");
    } else {

        fprintf(paginaHTML, "<html>\n"
                "<head>\n"
                "<script type=\"text/javascript\" src=\"dati.js\"></script>\n"
                "</head>\n"
                "<body>\n"
                "<select id=\"listaRuoli\" onchange=\"cambiaRuolo()\">\n"
                "<script>\n");
        fclose(paginaHTML);
    }
    return paginaHTML;
}

FILE* fineHTML(FILE* paginaHTML, char nomeFile[]){     

    paginaHTML = fopen(nomeFile, "a");
    if (paginaHTML == NULL) {
        printf("Impossibile aprire la pagina.");
    } else {

        fprintf(paginaHTML, "</script>\n"
                "</select>\n"
                "<br><br>\n\n"
                "<p id=\"demo\"></p>\n"
                "<script>\n"
                "cambiaRuolo()\n"
                "</script>\n"
                "</body>\n"
                "</html>\n");
        fclose(paginaHTML);
    }
    return paginaHTML;
}

FILE* baseJavascript(FILE* javascript, char nomeFile[]){
    javascript = fopen(nomeFile, "w");
    if (javascript == NULL) {
        printf("Impossibile aprire il file javascript.");
    } else {

        fprintf(javascript, "function inserisciRuolo(ruolo, nomi){\n"
                "document.write(\"<option value=\\\"\"+nomi+\"\\\">\"+ruolo+\"</option>\")\n"
                "}\n"
                "function cambiaRuolo(){\n"
                "var e = document.getElementById(\"listaRuoli\").value\n"
                "var lista=e.split(\"\\n\")\n"
                "document.getElementById(\"demo\").innerHTML = \"<textarea readonly rows=\\\"\"+(lista.length+1)+\"\\\" cols=\\\"30\\\">\" + e + \"</textarea>\"\n"
                "}\n");
        fclose(javascript);
    }
    return javascript;
}

int controlloFileStringa(char nomeFile[], char s[]){        
    int presenzaStringa=0;
    FILE* controllaFile;
    char riga[MAX_STRLEN + 1];
    
    controllaFile = fopen(nomeFile, "r");
    if (controllaFile == NULL) {
        printf("Impossibile aprire la pagina.");
    } else {
        fscanf(controllaFile, "%s", riga);
            while (!feof(controllaFile)) {
                if (!(strstr(riga, s)== NULL)){
                    presenzaStringa=1;
                }
               fscanf(controllaFile, "%s", riga); 
            }
    }
    fclose(controllaFile);
    return presenzaStringa;
}

FILE* inserisciRuolo(FILE* javascript, char nomeFile[], char ruolo[], int i){      
    javascript = fopen(nomeFile, "a");
    if (javascript == NULL) {
        printf("Impossibile aprire il file javascript.");
    } else {
        fprintf(javascript, "\nvar ruolo%d=\"%s\"\n"
                "var nomi%d=\"",i,ruolo,i);
        fclose(javascript);
    }
    return javascript;
}

FILE* inserisciNome(FILE* javascript, char nomeFile[], char nome[]){        
    javascript = fopen(nomeFile, "a");
    if (javascript == NULL) {
        printf("Impossibile aprire il file javascript.");
    } else {
        fprintf(javascript, "%s",nome);
        fclose(javascript);
    }
    return javascript;
}

FILE* inserisciDivisione(FILE* javascript, char nomeFile[]){
    javascript = fopen(nomeFile, "a");
    if (javascript == NULL) {
        printf("Impossibile aprire il file javascript.");
    } else {
        fprintf(javascript, "\\n");
        fclose(javascript);
    }
    return javascript;
}

FILE* implementaDati(FILE* paginaHTML, char nomePagina[], FILE* javascript, char nomeDati[], int i){
    javascript = fopen(nomeDati, "a");
    if (javascript == NULL) {
        printf("Impossibile aprire il file javascript.");
    } else {
        fprintf(javascript, "\"\n");
        fclose(javascript);
    }
    
    paginaHTML = fopen(nomePagina, "a");
    if (paginaHTML == NULL) {
        printf("Impossibile aprire la pagina.");
    } else {
        fprintf(paginaHTML, "inserisciRuolo(ruolo%d,nomi%d)\n", i, i);
        fclose(paginaHTML);
    }
    return paginaHTML;
}