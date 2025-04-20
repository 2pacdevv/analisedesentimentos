Esse codigo lê um texto de até 10 paragrafos e diz sua polaridade, se é um texto positivo ou negativo, observe, sua sintaxe para funcionar é
- numero de paragrafos
- paragrafos
- palavras boas
- palavras ruins
- numero de perguntas
- perguntas

entradas e saídas esperadas
--- 
as perguntas são: 
Questão 1: Polaridade geral do texto.

Questão 2: Polaridade do parágrafo 1.

Questão 3: Polaridade da maior sentença (em caracteres).

Questão 4: Polaridade da maior sentença (em palavras).

# Entrada 1
3
O sol brilha intensamente. O céu está azul e as aves cantam. As pessoas estão felizes e sorridentes.
A tempestade se aproxima. O vento uiva e a chuva cai forte. As pessoas correm para se abrigar.
O dia está comum. Nada de especial acontece. As pessoas seguem suas rotinas.
feliz sorridente alegre
triste tempestade chateado
4
1
2 1
3
4

# Saída 1
0 Palavras positivas, 1 Palavras negativas: Polaridade negativa
0 Palavras positivas, 1 Palavras negativas: Polaridade negativa
0 palavras positivas, 0 Palavras negativas: Polaridade neutra
0 palavras positivas, 0 Palavras negativas: Polaridade neutra


# Entrada 2
2
O filme foi decepcionante. A atuação foi ruim e o enredo confuso. Não recomendo a ninguém.
A comida estava ótima, mas o serviço foi péssimo. O ambiente era agradável, porém barulhento.
horrível decepcionante ruim péssimo
bom ótimo excelente agradável
5
1
2 1
2 2
3
4

# Saida 2
3 Palavras positivas, 1 Palavras negativas: Polaridade neutra
1 Palavras positivas, 1 Palavras negativas: Polaridade negativa
0 Palavras positivas, 0 Palavras negativas: Polaridade negativa
1 palavras positivas, 0 Palavras negativas: Polaridade positiva
1 palavras positivas, 0 Palavras negativas: Polaridade positiva
