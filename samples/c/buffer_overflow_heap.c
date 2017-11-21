int main (int argc, char ** argv) {
    FILE * fd;
    char * buf = (char *) malloc (8);
    char * arquivo = (char *) malloc (16);
    strcpy (arquivo, "/tmp/arquivo");
    gets (buf);
    printf ("Abrindo o arquivo: %s\n", arquivo);
    fd = fopen (arquivo, "w");
    fputs (buf, fd);
    fclose(fd);
    return 0;
}