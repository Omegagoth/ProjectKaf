#ifndef FENETRECONTROLE_H
#define FENETRECONTROLE_H

#include "wxIncludes.h"

class FenetreControle : public wxFrame
{
	public :
	
		FenetreControle();
		virtual ~FenetreControle();
	
	protected :
	
		wxSlider* vitesse_slider;
		wxComboBox* vue_liste;
		//wxCheckBox* filfer_bouton;
		//wxCheckBox* brouillard_bouton;
		
		void modifie_vitesse(wxScrollEvent& event);
		void modifie_vue(wxCommandEvent& event);
		void modifie_option(wxCommandEvent& event);
};


#endif

