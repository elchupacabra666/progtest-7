# Sirky (Matchsticks Puzzle)

Úkolem je napsat program, který dokáže řešit hlavolam **„přeskakování sirek“**.

Tento hlavolam má jednoduché zadání: na stole leží `n` sirek v řadě vedle sebe. Úkolem je z těchto sirek vytvořit **„křížky“**, tedy přesunout sirku o `k` pozic vlevo nebo vpravo a položit ji křížem přes ležící sirku.

- Sirku lze přemístit pouze jednou, dokud leží samostatně (nelze tedy rozebrat křížek).
- Sirku lze přesunout vlevo nebo vpravo, při přesunutí je potřeba přeskočit zadaný počet ležících sirek.
- Přeskakovaná samostatná sirka se počítá za 1, křížek za 2.

## Příklad

```
0   1   2   3   4   5   6   7   8   9  10  11  

|   |   |   |   |   |   |   |   |   |   |   |   

4R

|   |   |   |       |   |   |   |   X   |   |   

8L

|   |   X   |       |   |   |       X   |   |   

5R

|   |   X   |           |   |       X   X   |   

7L

|   X   X   |           |           X   X   |   

0R

    X   X   X           |           X   X   |   

6R

    X   X   X                       X   X   X
```

## Vstup

Program přijímá dvě celá čísla `n` a `k`:

- `n`: počet sirek (n > 1)
- `k`: velikost skoku (k ≥ 0)

## Výstup

Program zobrazí všechny posloupnosti přesunů sirek, kterými lze pro daný vstup vytvořit křížky. Každá posloupnost přesunů je na zvláštní řádce.

- Na řádce jsou čárkami oddělené jednotlivé přesuny.
- Pro každý přesun je určeno číslo sirky (počítáno od nuly) a směr posunutí (`L` nebo `R`).
- Poslední řádka výstupu udává počet různých existujících řešení.

### Chybové stavy

Program detekuje chybu, pokud:

- Na vstupu jsou nečíselné hodnoty.
- Počet sirek (`n`) je menší nebo roven jedné.
- Velikost skoku (`k`) je záporná.

V případě chyby je zobrazeno chybové hlášení podle vzoru v ukázce. Za chybovým hlášením je odřádkování, chybové hlášení zobrazujte na standardní výstup.

### Ukázkový běh programu

```
Pocet sirek:
8
Velikost skoku:
2
3R,5L,0R,4R
3R,5L,0R,7L
3R,5L,2L,4R
3R,5L,2L,7L
3R,5L,4R,0R
3R,5L,4R,2L
3R,5L,7L,0R
3R,5L,7L,2L
4L,2R,0R,5R
4L,2R,0R,7L
4L,2R,3L,5R
4L,2R,3L,7L
4L,2R,5R,0R
4L,2R,5R,3L
4L,2R,7L,0R
4L,2R,7L,3L
Celkem reseni: 16
```

```
Pocet sirek:
2
Velikost skoku:
0
0R
1L
Celkem reseni: 2
```

```
Pocet sirek:
4
Velikost skoku:
1
Celkem reseni: 0
```

```
Pocet sirek:
-1
Nespravny vstup.
```

```
Pocet sirek:
10
Velikost skoku:
abcd
Nespravny vstup.
```

### Poznámky

- Možným řešením je systematicky procházet možné tahy a testovat, zda vedou k cíli.
- Pro testování všech možných kombinací tahů se hodí rekurze.
- Není úkolem implementovat efektivní algoritmus hledání řešení. Předpokládá se použití hrubé výpočetní síly.
- Uvědomte si ale, že možných tahů, které je potřeba otestovat, existuje velké množství (až `n! / (n/2)!`).
- Implementace vlastního testování by měla být rozumně rychlá a neměla by provádět zbytečné úkony.

