# Studentendatenverwaltungsprojekt in C

Dieses Projekt wurde im Rahmen einer C-Programmierübung entwickelt und dient zur Verwaltung von Studentendaten mittels mehrerer Dateien.

## Projektbeschreibung

Das Studentendatenverwaltungsprojekt ist eine Konsolenanwendung, die es Benutzern ermöglicht, Studentendaten einzugeben, anzuzeigen, zu bearbeiten und zu löschen. Die Daten jedes Studenten werden in einer strukturierten Form gespeichert, wobei folgende Informationen erfasst werden:

- Vorname und Nachname des Studenten
- Eindeutige Matrikelnummer
- Alter des Studenten
- Studiengang, in dem der Student eingeschrieben ist

Die Anwendung ermöglicht auch die Auswahl des Studiengangs aus einer Liste von verfügbaren Studiengängen, die in der Datei `courses.txt` gespeichert sind.

## Funktionalitäten

- **Hinzufügen eines neuen Studenten:** Benutzer können die Details eines neuen Studenten einschließlich Vorname, Nachname, Matrikelnummer, Alter und Studiengang erfassen. Die Matrikelnummer wird automatisch generiert, um Eindeutigkeit zu gewährleisten.

- **Anzeigen aller gespeicherten Studentendaten:** Die Anwendung ermöglicht es, alle vorhandenen Studentendaten in einer übersichtlichen Tabelle anzuzeigen. Diese Ansicht enthält alle erfassten Informationen für jeden Studenten.

- **Löschen eines Studenten:** Benutzer können einen Studenten anhand seiner Matrikelnummer aus der Datenbank löschen. Dies wird durch die eindeutige Matrikelnummer gewährleistet.

- **Studiengangsauswahl:** Beim Hinzufügen eines neuen Studenten wird eine Liste der verfügbaren Studiengänge aus `courses.txt` angezeigt, aus der der Benutzer auswählen kann. Dadurch wird sichergestellt, dass der ausgewählte Studiengang korrekt erfasst wird.

## Projektstruktur

- `main.c`: Diese Datei enthält die Hauptfunktion und die Benutzerschnittstelle, einschließlich Menüführung und Nutzerinteraktion.

- `student.c`: Hier sind Funktionen implementiert, die direkt mit der Verwaltung von Studentendaten verbunden sind. Dies umfasst das Hinzufügen, Löschen und Anzeigen von Studenten.

- `file.c`: Diese Datei enthält Funktionen, die für die Dateiverwaltung zuständig sind. Das Lesen und Schreiben von Daten in Dateien wird hier umgesetzt.

- `students.txt`: In dieser Datei werden die Studentendaten in einem strukturierten Format gespeichert.

- `courses.txt`: Diese Datei enthält eine Liste der verfügbaren Studiengänge, die beim Hinzufügen eines neuen Studenten angezeigt werden.

## Verwendung

1. **Klonen des Repositories:** Klonen Sie dieses Repository in das gewünschte Verzeichnis auf Ihrem Computer.

