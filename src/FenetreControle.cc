#include "FenetreControle.h"
#include "Application.h"




FenetreControle::FenetreControle()
: wxFrame(0, wxID_ANY, wxT("Contrôle"), wxDefaultPosition, wxSize(450,350), wxCAPTION)
{
	wxBoxSizer* horiz_sizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* vert_sizer = new wxBoxSizer(wxVERTICAL);
	
	wxFont policeGras(10, wxDEFAULT, wxNORMAL, wxBOLD);
	
	
	wxStaticText* simulation = new wxStaticText(this, wxID_ANY, wxT("Simulation :"));
	simulation->SetFont(policeGras);
	
	wxStaticText* vitesse_texte = new wxStaticText(this, wxID_ANY, wxT("Vitesse de rotation des particules : "));
	
	vitesse_slider = new wxSlider(this, wxID_ANY, 30, 0, 100);
	
	wxFlexGridSizer* vue_sizer = new wxFlexGridSizer(1, 2, 3, 10);
	
	wxStaticText* affichage = new wxStaticText(this, wxID_ANY, wxT("Affichage :"));
	affichage->SetFont(policeGras);
	
	wxStaticText* vue_texte = new wxStaticText(this, wxID_ANY, wxT("Type de vue"));
	
	vue_liste = new wxComboBox(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY | wxCB_DROPDOWN);
	vue_liste->Append(wxT("Camera libre (FreeFly)"));
	vue_liste->Append(wxT("Suivre une particule (Traking)"));
	vue_liste->SetSelection(0);
	
	//wxStaticText* option = new wxStaticText(this, wxID_ANY, wxT("Option :"));
	
	/*filfer_bouton = new wxCheckBox(this, wxID_ANY, wxT("Mode fil de fer"));
	filfer_bouton->SetValue(false);
	
	brouillard_bouton = new wxCheckBox(this, wxID_ANY, wxT("Brouillard"));
	brouillard_bouton->SetValue(false);*/
	
	wxStaticText* consigne_texte = new wxStaticText(this, wxID_ANY, wxT("Consigne :"));
	consigne_texte->SetFont(policeGras);
	wxStaticText* consigne1 = new wxStaticText(this, wxID_ANY, wxT("_Maintenir le clic droit enfoncé pour pouvoir bouger"));
	wxStaticText* consigne2 = new wxStaticText(this, wxID_ANY, wxT(" la caméra avec la souris"));
	wxStaticText* consigne3 = new wxStaticText(this, wxID_ANY, wxT("_Appuyer sur les touche directionnelles pour vous déplacer"));
	wxStaticText* consigne4 = new wxStaticText(this, wxID_ANY, wxT(" en caméra libre"));
	wxStaticText* consigne5 = new wxStaticText(this, wxID_ANY, wxT("_Appuyer sur page up ou down pour monter ou descendre en"));
	wxStaticText* consigne6 = new wxStaticText(this, wxID_ANY, wxT(" caméra libre"));
	wxStaticText* consigne7 = new wxStaticText(this, wxID_ANY, wxT("_Bouger la molette ou appuyer sur w et s pour zoomer"));
	
	
	vert_sizer->Add(simulation, 0, wxTOP, 20);
	
	vert_sizer->Add(vitesse_texte, 0, wxTOP, 10);
	
	vert_sizer->Add(vitesse_slider, 1, wxTOP | wxEXPAND, 10);
	
	
	
	vert_sizer->Add(affichage, 0, wxTOP, 10);
	
	vue_sizer->Add(vue_texte, 0, wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
	vue_sizer->Add(vue_liste, 1, wxEXPAND);
	
	vert_sizer->Add(vue_sizer, 0, wxTOP | wxEXPAND, 10);
	
	/*vert_sizer->Add(option, 0, wxTOP, 10);
	
	vert_sizer->Add(filfer_bouton, 0, wxTOP, 10);
	vert_sizer->Add(brouillard_bouton, 0, wxTOP, 10);*/
	
	vert_sizer->Add(consigne_texte, 0, wxTOP, 10);
	vert_sizer->Add(consigne1, 0, wxTOP, 10);
	vert_sizer->Add(consigne2, 0, wxTOP, 10);
	vert_sizer->Add(consigne3, 0, wxTOP, 10);
	vert_sizer->Add(consigne4, 0, wxTOP, 10);
	vert_sizer->Add(consigne5, 0, wxTOP, 10);
	vert_sizer->Add(consigne6, 0, wxTOP, 10);
	vert_sizer->Add(consigne7, 0, wxTOP, 10);
	
	
	horiz_sizer->Add(vert_sizer, 1, wxRIGHT | wxLEFT | wxEXPAND, 20);
	
	SetSizer(horiz_sizer);
	
	Show();
	
	Connect(wxID_ANY, wxEVT_COMMAND_SLIDER_UPDATED, wxScrollEventHandler(FenetreControle::modifie_vitesse));
	Connect(wxID_ANY, wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(FenetreControle::modifie_vue));
	//Connect(wxID_ANY, wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(FenetreControle::modifie_option));
	
	
}

FenetreControle::~FenetreControle()
{}

void FenetreControle::modifie_vitesse(wxScrollEvent& event)
{
	wxGetApp().setvitesse(vitesse_slider->GetValue());
}

void FenetreControle::modifie_vue(wxCommandEvent& event)
{
	if(vue_liste->GetSelection() == 0)
	{
		wxGetApp().setcamera(Vue(Libre));
	}
	else
	{
		wxGetApp().setcamera(Vue(Suivre));
	}
}

/*void FenetreControle::modifie_option(wxCommandEvent& event)
{
	wxGetApp().setmode_fildefer(filfer_bouton->GetValue());
	wxGetApp().setbrouillard(brouillard_bouton->GetValue());
}*/


