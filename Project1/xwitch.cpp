#pragma once
#include "xwitch.h"

//Team-Switch
std::string teamSwitch(int nr) {
	switch (nr)
	{
	case 1: return "Ferrari";
	case 2: return "McLaren";
	case 3: return "RedBull";
	case 4: return "Mercedes";
	default:
		return "Ungueltige Eingabe!";
	}
}

//Place-Point-Translator
int placeTranslator(int pl) {
	switch (pl)
	{
	case 1:  return 25;
	case 2:  return 18;
	case 3:  return 15;
	case 4:  return 12;
	case 5:  return 10;
	case 6:  return 8;
	case 7:  return 6;
	case 8:  return 4;
	case 9:  return 2;
	case 10: return 1;
	default:
		return 0;
	}
}

//Circuit-Switch
std::string circNames(int nr) {
	switch (nr)
	{
	case 1: return "Australien - Melbourne";
	case 2: return "Malaysia - Sepang";
	case 3: return "Bahrain - Sachir";
	case 4: return "China - Schanghai";
	case 5: return "Spanien - Barcelona";
	case 6: return "Monaco - Monte Carlo";
	case 7: return "Kanada - Montreal";
	case 8: return "Oesterreich - Spielberg";
	case 9: return "Grossbritannien - Melbourne";
	case 10: return "Deutschland - Hockenheim";
	case 11: return "Ungarn - Budapest";
	case 12: return "Belgien - Spa-Francorchamps";
	case 13: return "Italien - Monza";
	case 14: return "Singapur - Singapur";
	case 15: return "Japan - Suzuka";
	case 16: return "Russland -	Sotschi";
	case 17: return "USA - Austin";
	case 18: return "Brasilien - Sao Paulo";
	case 19: return "Abu Dhabi - Abu Dhabi";
	default:
		break;
	}
}