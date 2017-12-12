//
// Created by blackrosezy on 12-Dec-17.
//

#ifndef ALL_IMAGEPANEL_H
#define ALL_IMAGEPANEL_H

#include <wx/wx.h>

class ImagePanel : public wxPanel {
public:
    ImagePanel(wxDialog *parent, wxString fileName);

    void paintEvent(wxPaintEvent &event);

    void render(wxDC &dc);

    void OnSize(wxSizeEvent &event);

private:
    wxImage image;
    wxBitmap resized;
    int w, h;


};


#endif //ALL_IMAGEPANEL_H
