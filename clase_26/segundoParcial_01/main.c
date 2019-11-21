#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Entregas.h"
#include "utn.h"

int main()
{
    LinkedList* registro = ll_newLinkedList();

    if(!controller_loadFromText("data.csv",registro))
    {
        controller_saveAsText("informe.txt",registro);
    }
    return 0;
}
