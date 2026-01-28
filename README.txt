Projeto
Para compilar e rodar o projeto:
    #gcc -o main sim.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 && ./main
Isso garante que o projeto e suas bibliotecas sejam devidamente compilados e executados.

O projeto simula a colisão elástica entre partículas. Na situação onde não existem forças externas atuando sobre o sistema, uma colisão elática tem energia cinética total do sistema inalterada após a colisão. Uma vez que seja elática, a energia cinética é conservada. Disso seguem as equações características de 1 Dimensão:

M1V1 + M2V2 = M1V'1 + M2V'2

A mesma coisa para energia cinética.

Para 2 dimensões (Caso do projeto, com eixos cartesianos x e y), a lógica da colisão é alterada, mesmo porquê, agora corpos podem rotacionar em torno do seu próprio eixo, sendo preciso repensar toda a dinâmica nesse caso.
Apesar disso, o projeto leva em consideração apenas partículas não-rodantes (Acho que essa palavra não existe, mas eu me referi a partículas que não giram em torno do seu eixo).

Com o objetivo de calcular a velocidade final, eu usei duas forma:

1 - Sem angulo:
Nessa abordagem, usa-se o produto interno etc...
Nao é preciso usar os angulos. particularmente, nao gostei muito

2 - Com os angulos
Usa Dinamica simples e Triangulação, gostei mais, além de ser bem mais simples de desenvolver as formulas

\---------------------------------------------------------------------------------------------------------------------------------------------------------\
Divisão do Projeto
-- sim.c
-> Posui o loop principal do raylib e a lógica de:
    Atualização
    Checagem de restrições
    Draw

-- Particulas.h
-> Definição das partículas e metódos correlatos. Aqui eu coloco TODAS as características que relacionam com partículas, por isso, Desenhar, Update e TratarColisão são feitos nesse Header.

-- Equacoes*.h
-> Headers com as definições das equações

-- GlobalVariables.h
-> Parametrização geral do programa:
     Tamanho da tela
     Tamanho população de partículas.

\---------------------------------------------------------------------------------------------------------------------------------------------------------\
Problemas
Um problema notório é relacionado com a detecção da colisão. As partículas acabam se colidindo muitas vezes ao se encontarem, isso é um problema, pois acabam se "agrupando", no fim, adicionei uma condição de aproximação. Acredito que ela seja a responsável por fazer meu sistema perder energia. Ou mesmo ganhar.

De qualquer forma, para um projeto inicial, está ótimo!

\---------------------------------------------------------------------------------------------------------------------------------------------------------\
Material Usado
Teoria e equações:
https://williamecraver.wixsite.com/elastic-equations
https://gkfweb.math.illinois.edu/math198/MA198-2013/dprorok2/FearTheSpherePPT.pdf
https://en.wikipedia.org/wiki/Elastic_collision
