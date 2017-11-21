int main (int argc, char ** argv) {
    char a[33];
    memset(a, 'a', 32);
    a[32] = '\0';
    printf("Tamanho de a = %d\n", strlen(a));
    return 0;
}
