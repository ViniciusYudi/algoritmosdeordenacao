# Atividade Algoritmos de Ordenação - Introdução:

- Foram utilizados os algoritmos de ordenação BubbleSort e QuickSort para a ordenação do csv "restaurante_pratos.csv", presente aqui também.

- O header file "read_csv.h" segue anexado também, e cumpre importante papel em ler o arquivo csv e transformá-lo em um array bidimensional. Existem métodos e funções que não são utilizados, mas que, se necessário, estão prontos.

- Realizei DUAS MAINS diferentes, cada uma com um dos algoritmos, apenas por capricho e clareza na compreensão do código.

# Relatório:

- Ao aplicar o QuickSort no dataset, o tempo médio de ordenação (excluindo o tempo em que ele passa imprimindo o array ordenado) foi de 53 milissegundos, e foi calculado por meio da biblioteca chrono. 

- Ao aplicar o BubbleSort no dataset, o tempo médio de ordenação (excluindo o tempo em que ele passa imprimindo o array ordenado) foi de 594133 milissegundos, e também foi calculado por meio da biblioteca chrono.

- Com isso, é possível concluir que o algoritmo de QuickSort é DE FATO mais eficiente dado um array de 300.000 linhas ou mais, ao contrário do BubbleSort, que NÃO se mostra eficiente nesse caso, sendo visível pela DRÁSTICA diferença entre ambos.

- A escolha do pivô no QuickSort foi simples, onde utilizamos o primeiro elemento do subarray, e após a partição o pivô é movido pra posição correta do array, e, em cada chamada recursiva da função quickSort, cada subarray define seu próprio pivô.

