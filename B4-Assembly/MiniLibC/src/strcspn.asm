BITS 64

SECTION .text
GLOBAL strcspn

strcspn:
    XOR RCX, RCX ; je set mon compteur à 0
    MOV R8, RSI ; je set une copie de mon pointeur de ma liste de verification
    JMP _loop

_loop:
    MOV AL, BYTE [RDI] ; je charge le caractere de RDI dans AL
    JMP _handle_char ; je lance la boucle de verification du char

_handle_char:
    CMP BYTE [RSI], AL ; je compare mon char de ma string avec le premier char de ma liste de reject
    JE _exit ; si le char appartient à mes reject j'exit mon programme
    CMP BYTE [RSI], 0 ; si mon char atteint la fin de la liste des reject
    JE _reload ; je relance ma loop initiale en modifiant les valeurs
    INC RSI ; sinon je me déplace dans ma liste de reject
    JMP _handle_char ; et je relance ma verification

_reload:
    INC RCX ; j'incrémente mon compteur de char absent de la liste
    MOV RSI, R8; je reset la valeur de mon pointeur à sa valuer d'origine
    INC RDI ; je me déplace dans ma string à vérifier
    JMP _loop ; je relance ma loop d'origine

_exit:
    MOV RAX, RCX ; je set ma valeur de retour à mon compteur
    RET ; je return RAX
