//#include <wx/wx.h>
//
//class app : public wxapp {
//public:
//    bool oninit() {
//        wxframe* window = new wxframe(null, wxid_any, "gui test", wxdefaultposition, wxsize(600, 400));
//        wxboxsizer* sizer = new wxboxsizer(wxhorizontal);
//        wxstatictext* text = new wxstatictext(window, wxid_any, "dla bena",
//            wxdefaultposition, wxdefaultsize, wxalign_centre_horizontal);
//        text->setfont(wxfont(20, wxfontfamily_default, wxfontstyle_normal, wxfontweight_normal));
//        sizer->add(text, 1, wxalign_center);
//        window->setsizer(sizer);
//        window->show();
//        return true;
//    }
//};
//
//wximplement_app(app);