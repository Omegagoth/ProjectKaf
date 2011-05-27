#include "FenetreControle.h"




FenetreControle::FenetreControle()
: wxFrame(0, wxID_ANY, wxT("Contrôle"), wxDefaultPosition, wxSize(300,200), wxCAPTION)
{
	wxBoxSizer* horiz_sizer = new wxBoxSizer(wxHORIZONTAL);
	
	wxButton* bouton = new wxButton(this, wxID_ANY, wxT("Salut!"));
	
	horiz_sizer->Add(bouton, 1, wxEXPAND);
	
	SetSizer(horiz_sizer);
	
	Show();
	
	
}

FenetreControle::~FenetreControle()
{}


