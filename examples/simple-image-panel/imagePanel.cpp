//
// Created by blackrosezy on 12-Dec-17.
//

#include "imagePanel.h"

ImagePanel::ImagePanel(wxDialog *parent, wxString fileName) : wxPanel(parent) {
    image.LoadFile(fileName, wxBITMAP_TYPE_JPEG);
    w = -1;
    h = -1;
    SetDoubleBuffered(true);
    Bind(wxEVT_PAINT, &ImagePanel::paintEvent, this);
    Bind(wxEVT_SIZE, &ImagePanel::OnSize, this);
}

void ImagePanel::paintEvent(wxPaintEvent &event) {
    wxPaintDC dc(this);
    render(dc);
}

void ImagePanel::render(wxDC &dc) {
    int neww, newh;
    dc.GetSize(&neww, &newh);

    if (neww != w || newh != h) {
        resized = wxBitmap(image.Scale(neww, newh /*, wxIMAGE_QUALITY_HIGH*/ ));
        w = neww;
        h = newh;
        dc.DrawBitmap(resized, 0, 0, false);
    } else {
        dc.DrawBitmap(resized, 0, 0, false);
    }
}

void ImagePanel::OnSize(wxSizeEvent &event) {
    Refresh();
    //skip the event.
    event.Skip();
}
