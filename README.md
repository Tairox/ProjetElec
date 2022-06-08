# Projet Électronique : Capteur de pression atmosphérique

## Matériel nécessaire

* Grove HP206C
* Arduino UNO
* Dragino LoRa Shield 1.4
* Gateway Dragino (modèle à l'appréciation de chacun)

## Arborescence du projet

Le dossier `ArduinoRAW` contient le fichier .ino permettant d'afficher l'altitude en sortie de la carte Arduino uniquement.

Le dossier `ArduinoToCayenne` contient le fichier .ino permettant d'afficher l'altitude sur la plateforme IoT Cayenne.
## Où récupérer les données nécéssaires au calcul

Température et pression QNH : https://fr.allmetsat.com/metar-taf/france.php?icao=LFMH

Altitude de référence : https://www.geoportail.gouv.fr/

## Résultats

Les résultats sont accessibles sur https://developers.mydevices.com/cayenne/features/.

Cayenne est une plateforme IoT de type glisser-déposer, développée par myDevices, qui permet aux utilisateurs de prototyper et de partager rapidement leurs solutions IoT connectées. Ici, on l'utilise de concert avec __TTN__.
