#include "FenetreControle.h"




FenetreControle::FenetreControle()
: wxFrame(0, wxID_ANY, wxT("Contrôle"), wxDefaultPosition, wxSize(300,200), wxCAPTION)
{
	wxBoxSizer* horiz_sizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* vert_sizer = new wxBoxSizer(wxVERTICAL);
	
	
	
	horiz_sizer->Add(vert_sizer, 1, wxRIGHT | wxLEFT | wxEXPAND, 20);
	
	SetSizer(horiz_sizer);
	
	Show();
	
	
}

FenetreControle::~FenetreControle()
{}


