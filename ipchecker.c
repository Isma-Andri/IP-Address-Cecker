#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void get_query(char *query_string, int *ip1, int *ip2, int *ip3, int *ip4) {
    sscanf(query_string, "ip=%d.%d.%d.%d", ip1, ip2, ip3, ip4);
}

void html_html_header() {
    printf("Content-type: text/html\n\n");
    printf("<HTML><HEAD><TITLE>IP CHECKER</TITLE></HEAD><BODY>");
}

void html_style(){
    printf("<STYLE>\n");
    printf("BODY { BACKGROUND-COLOR: #F6EBBD; FONT-FAMILY: Arial, sans-serif; MARGIN: 0; PADDING: 0; }\n");
    printf("HEADER { BACKGROUND-COLOR: #512125; COLOR: WHITE; FONT-SIZE: 2rem; TEXT-ALIGN: CENTER; PADDING: 20px; }\n");
    printf("</STYLE>\n");
}

void html_title() {
    printf("<HEADER>IP Class</HEADER>");
}

void html_html_footer() {
    printf("<A href=\"http://localhost/ipchecker.html\">Retour</A><BR>");
    printf("</BODY></HTML>");
}

// Fonction pour déterminer la classe de l'adresse IP
char get_class(int ip1) {
    if (ip1 >= 0 && ip1 <= 127) {
        return 'A';
    } else if (ip1 >= 128 && ip1 <= 191) {
        return 'B';
    } else if (ip1 >= 192 && ip1 <= 223) {
        return 'C';
    } else if (ip1 >= 224 && ip1 <= 239) {
        return 'D';
    } else {
        return 'E';
    }
}

// Verifier les 4 octets de l'addresse IP
int verify(int ip1, int ip2, int ip3, int ip4) {
    if ((ip1 >= 0 && ip1 <= 255) &&
        (ip2 >= 0 && ip2 <= 255) &&
        (ip3 >= 0 && ip3 <= 255) &&
        (ip4 >= 0 && ip4 <= 255)) {
        return 0; // L'adresse IP est valide
    } else {
        return 1; // L'adresse IP invalida
    }
}

// Fonction pour vérifier l'adresse IP fournie par la query string
void check_ip() {
    char *query_string = getenv("QUERY_STRING");
    int ip1, ip2, ip3, ip4;

    // Extraction des valeurs IP depuis la query string
    get_query(query_string, &ip1, &ip2, &ip3, &ip4);
    char class = get_class(ip1);

    // Génération du HTML
    html_html_header();
    html_style();
    html_title();

    // Vérification de l'adresse IP
    int result = verify(ip1, ip2, ip3, ip4);
    if (result == 0) {
        printf("<P>Class: %c</P>", class);
        printf("<P>IP: %d.%d.%d.%d</P>", ip1, ip2, ip3, ip4);
    } else {
        printf("<P>Invalid IP address</P>");
    }

    // Manidy kkk
    html_html_footer();
}

int main() {
    check_ip();
    return 0;
}
