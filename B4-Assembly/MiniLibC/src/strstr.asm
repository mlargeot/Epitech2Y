BITS 64

SECTION .text
GLOBAL strstr

strstr:
    MOV RCX, RSI ; je save l'adresse de ma substring
    MOV R8, RDI ; je save l'adresse de ma string de recheche
    CMP BYTE [RSI], 0 ; sinon si la string que je cherche est est un nullbyte
    JE _exit ; j'exite le programme en revoyant simplement la string dans laquelle je cherche
    CMP BYTE [RDI], 0 ; je compare si la string dans laquelle je cherche est un nullbyte
    JE _exit_null ; si oui je revoie null
    JMP _loop ; sinon je lance ma loop

_loop:
    CMP BYTE [RDI], 0 ; si j'arrive à la fin de ma string de recherche
    JE _exit_null ; dans ce cas je retourne NULL
    MOV AL, BYTE [RDI] ; je charge le premier char de ma string de recherche dans AL 
    CMP AL, BYTE [RSI]; je teste le premier car des deux strings avant de lancer un recherche complete
    JNE _increment ; si les premiers chars ne sont pas égaux dans ce cas je relance ma loop sans lancer de verif
    JE _search_sub ; s'ils sont égaux je tente de chercher ma substring dans ma string

_search_sub:
    INC RSI ; j'incremente mes pointeurs
    INC RDI
    MOV AL, BYTE [RDI] ; je déréférence mes pointeurs pour comparer leur valeur
    MOV BL, BYTE [RSI]
    CMP BL, 0 ; si j'arrive au nullbyte de ma substring dans ce cas je l'ai trouvée
    JE _exit ; j'exit donc avec le pointeur save dans r8
    CMP AL, BL ; sinon je compare mes deux valeurs
    JE _search_sub ; si elles sont égales je relance ma recherche avec les valeurs suivantes
    JNE _increment ; si elles sont différentes je relance ma loop principale en remettant les nouveaux pointeurs

_increment:
    INC R8 ; j'incremente l'adresse de ma string de recherche
    MOV RDI, R8 ; je remet le départ de RDI à l'adresse de la string
    MOV RSI, RCX ; je remet le départ de RSI à l'adresse de la substring
    JMP _loop ; je relance ma loop

_exit:
    MOV RAX, R8 ; je set ma valeur de retour au pointeur de recherche save
    RET

_exit_null:
    MOV RAX, 0 ; je set ma valeur de retour à NULL
    RET
