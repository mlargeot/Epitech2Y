BITS 64

SECTION .text
GLOBAL strlen

strlen:

    XOR RAX, RAX ; set le registre rax à 0 (compteur)
    JMP .loop ; lancer la boucle

.loop:
    CMP BYTE [RDI], 0 ; comparer si la déréférence du registre rdi est un nullbyte
    JE _exit ; si RDI est un null byte je go dans le label exit
    INC RAX ; sinon j'incrémente RAX mon compteur et RDI mon pointeur dans la string et je relance un tour de boucle
    INC RDI
    JMP .loop

_exit:
    RET