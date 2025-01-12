import random

def gerar_sequencia(tamanho, numero_repetido, numero_ocorrências):
  """
  Gera uma sequência aleatória com um número específico se repetindo um número determinado de vezes.

  Args:
    tamanho: O tamanho desejado da sequência.
    numero_repetido: O número que será repetido.
    numero_ocorrências: Quantas vezes o número deve ser repetido.

  Returns:
    Uma lista com a sequência gerada.
  """

  sequencia = [random.randint(1, 100) for _ in range(tamanho)]
  indices_aleatorios = random.sample(range(tamanho), numero_ocorrências)

  for indice in indices_aleatorios:
    sequencia[indice] = numero_repetido

  return sequencia

# Gerando e imprimindo a sequência
sequencia_final = gerar_sequencia(10000, 555, 10)
for numero in sequencia_final:
  print(numero)