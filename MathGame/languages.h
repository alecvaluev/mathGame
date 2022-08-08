struct Word 
{
    char str[36];
};

struct Language
{
    struct Word words[44];
};

struct Language program = { {""} };

struct Language English = {
    {"      WELCOME\n\n",       //0
     ">> 1.START GAME <<\n",      //1
     ">> 2.SETTINGS   <<\n",      //2
     ">> 3.RANK       <<\n",
     ">> 4.EXIT       <<\n",      
     "The program is shut down\n\n",  //5
    "      GAME MODE\n\n", 
    ">> 1.SCORING       <<\n", 
    ">> 2.SURVIVING     <<\n", 
    ">> 3.LEVELS        <<\n", 
    ">> 5.BACK          <<\n",//10
    "\nSCORE: % d\n", "GAME OVER", //12
    "CHOOSE THE LEVEL\n\n", 
    " >> 1.EASY   <<\n", 
    " >> 2.MEDIUM <<\n", //15
    " >> 3.HARD   <<\n",
    "\nLIVES: %d\n",
    " LEVEL SETTINGS\n\n",  
    "        SETTINGS\n\n", 
    ">> 1.SCREEN RESOLUTION <<\n", //20 
    ">> 2.LANGUAGE          <<\n",
    ">> 3.BACK              <<\n",
    " SCREEN RESOLUTION\n\n", 
    ">> 1.MINI SCREEN <<\n", 
    ">> 2.FULL SCREEN <<\n", //25
    ">> 3.BACK        <<\n",
    "   LANGUAGE\n\n", 
    ">> 1.ENGLISH <<\n", 
    ">> 2.SPANISH <<\n", 
    ">> 3.FRENCH  <<\n", //30
    ">> 4.BACK    <<\n",//31
    "           RANK\n\n",//32
    "scoring","surviving",//33,34
    "(Press Enter to Continue)", //35
    "      CUSTOMIZATION\n\n",
    "ADDITION",
    "SUDTRACTION",
    "MULTIPLICATION",
    "DIVISION", //40
    "MODULO",
    ">> 6.BACK            <<\n",
    ">> 4.CUSTOMIZATION <<\n"}//43
};

struct Language Spanish = {
    {"      BIENVENIDO\n\n",
    ">> 1.INICIAR EL JUEGO <<\n",
    ">> 2.AJUSTES          <<\n",
    ">> 3.RANGO            <<\n",
    ">> 4.SALIDAR          <<\n",
    "El programa esta apagar\n\n",
    "      MODO DE JUEGO\n\n", 
    ">> 1.PUNTUACION      <<\n", 
    ">> 2.SOBREVIVIENTE   <<\n", 
    ">> 3.NIVELES         <<\n",
    ">> 5.VOLVER          <<\n ",
    "\nPUNTUACION:% d\n", "JUEGO TERMINADO",
    " ELIGE EL NIVEL\n\n", 
    ">> 1.FACIL    <<\n", 
    ">> 2.MEDIO    <<\n", 
    ">> 3.DIFICIL  <<\n",
    "\nVIDAS:% d\n",
    "AJUSTES DE NIVEL\n\n",
    "          LOS AJUSTES\n\n", 
    ">> 1.RESOLUCION DE PANTALLA <<\n", 
    ">> 2.IDIOMA                 <<\n", 
    ">> 3.VOLVER                 <<\n",
    "  RESOLUCION DE PANTALLA\n\n", 
    ">> 1.MINI PANTALLA      <<\n", 
    ">> 2.PANTALLA COMPLETA  <<\n", 
    ">> 3.VOLVER             <<\n",
    "   EL IDIOMA\n\n", 
    ">> 1.INGLES  <<\n", 
    ">> 2.ESPANOL <<\n", 
    ">> 3.FRANCES <<\n", 
    ">> 4.VOLVER  <<\n",
    "          RANGO\n\n",
    "puntuacion","sobreviviente",
    "(Presione Entrar para Continuar)",
    "  PERSONALIZACION\n\n", 
    "ADICION", 
    "RESTA", 
    "MULTIPLICACION", 
    "DIVISION", // 40 
    "MODULO", 
    ">> 6. VOLVER         <<\n", 
    ">> 4.PERSONALIZACION <<\n"}
};

struct Language French = {
{   "       BIENVENUE\n\n",
    ">> 1.DEMARRER LE JEU <<\n",
    ">> 2.PARAMETRES      <<\n",
    ">> 3.RANG            <<\n",
    ">> 4.SORTIR          <<\n",
    "Le programme est arrete\n\n",
    "          MODE JEU\n\n",
    ">> 1.SCORE            <<\n",
    ">> 2.SURVIVANT        <<\n",
    ">> 3.NIVEAUX          <<\n",
    ">> 5.REVENIR          <<\n",
    "\nSCORE:% d\n", "JEU FINI",
    "CHOISISSEZ LE NIVEAU\n\n",
    " >> 1.FACILE     <<\n",
    " >> 2.MOYEN      <<\n",
    " >> 3.DIFFICILE  <<\n",
    "\nVIVES:% d\n",
    "PARAMETRES DE NIVEAU\n\n",
    "        PARAMETRES\n\n",
    ">> 1.RESOLUTION D'ECRAN <<\n",
    ">> 2.LANGUE             <<\n",
    ">> 3.REVENIR            <<\n",
    " RESOLUTION D'ECRAN\n\n",
    ">> 1.ECRAN MINI   <<\n",
    ">> 2.ECRAN PLEIN  <<\n",
    ">> 3.REVENIR      <<\n",
    "     LANGUE\n\n",
    ">> 1.ANGLAIS  <<\n",
    ">> 2.ESPAGNOL <<\n",
    ">> 3.FRANCAIS <<\n",
    ">> 4.REVENIR  <<\n",
    "           RANG\n\n",
    "score","survivant",
    "(Appuyez sur Entree pour Continuer)",
    "    PERSONNALISATION\n\n", 
    "ADDITION", 
    "SOUSTRACTION", 
    "MULTIPLICATION", 
    "DIVISION", // 40 
    "MODULO", 
    ">> 6. REVENIR        <<\n", 
    ">> 4.PERSONNALISATION <<\n"}
};