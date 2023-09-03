# Sieb des Eratosthenes mit Bitmanipulation - Implementierung in C

## Einführung
Dieses Projekt enthält eine C-Implementierung des Siebs des Eratosthenes, einem effizienten Algorithmus zur Ermittlung von Primzahlen innerhalb eines gegebenen Bereichs. Die Besonderheit dieser Implementierung besteht darin, dass sie Bitmanipulation verwendet, um den Speicherbedarf zu reduzieren. Dieses Readme erklärt, wie das Sieb des Eratosthenes mit Bitmanipulation funktioniert und wie du die bereitgestellte Implementierung verwenden kannst.

## Wie funktioniert das Sieb des Eratosthenes mit Bitmanipulation?
Das Sieb des Eratosthenes mit Bitmanipulation basiert auf dem grundlegenden Funktionsprinzip des klassischen Siebs des Eratosthenes. Es verwendet jedoch ein Array von Bits (anstatt boolschen Werten), um den Status der Zahlen (prim oder nicht prim) darzustellen. Bitmanipulation ermöglicht eine effiziente Speichernutzung, da jedes Bit nur 1 oder 0 speichert.

Das Vorgehen bleibt das gleiche:
1. **Initialisierung:** Du erstellst ein Bit-Array, das alle Zahlen bis zu einer bestimmten Grenze repräsentiert. Zu Beginn sind alle Bits auf 1 gesetzt, was "prim" bedeutet.

2. **Markierung der Vielfachen:** Beginnend bei der kleinsten Primzahl (2), markierst du alle Vielfachen dieser Primzahl, indem du die entsprechenden Bits auf 0 setzt. Dies bedeutet, dass alle Vielfachen von 2 als "nicht prim" markiert sind.

3. **Weiter zur nächsten unmarkierten Zahl:** Gehe zur nächsten unmarkierten Zahl im Array (die nächste Primzahl) und markiere alle Vielfachen dieser Primzahl ebenfalls als "nicht prim".

4. **Wiederholung:** Wiederhole Schritt 3, bis du alle Primzahlen bis zur gewünschten Grenze gefunden hast.

5. **Ergebnis:** Die Primzahlen sind diejenigen Zahlen, deren entsprechende Bits im Array auf 1 stehen.

## Anwendung
1. **Kompilieren:** Um die Anwendung zu kompilieren, öffne das Terminal und navigiere zum Projektordner. Führe dann den folgenden Befehl aus:

   ```sh
   gcc sieve_of_eratosthenes.c -o sieve_of_eratosthenes
