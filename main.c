int main(){

    // to get the word
    int i = 0;
    do
    {
        scanf("%c", &ch_w);
        word[i] = ch_w;
        i++;
    } while (ch_w != '\t' && ch_w != '\n' && ch_w != ' ');
    word[i-1]='\0';

    // to get the txt
    i = 0;
    do
    {
        scanf("%c", &ch_t);
        txt[i] = ch_t;
        i++;
    } while (ch_t != '~');
   txt[i-1]='\0';

}