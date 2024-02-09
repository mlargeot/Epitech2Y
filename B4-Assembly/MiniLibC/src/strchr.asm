BITS 64

SECTION .text
GLOBAL strchr

strchr:

    JMP .loop ; lancer la boucle

.loop:
    CMP BYTE [RDI], SIL ;je compare le char de ma string (la déréférence du registre RDI) au char/int en paramètre
    JE _exit ; si ils sont égaux j'exit en retournant le pointeur
    CMP BYTE [RDI], 0 ;je compare l'eventualité ou je ne toruve pas mon char donc je suis à null byte
    JE _exit_null ; si je suis sur le nullbyte je retourne null
    INC RDI ;sinon j'incrémente mon pointeur et je refait un tour de boucle
    JMP .loop

_exit:
    MOV RAX, RDI
    RET

_exit_null:
    XOR RAX, RAX
    RET
