import gi  
gi.require_version('Gtk', '3.0')  
from gi.repository import Gtk  
  
class FileChooserNativeDemo(Gtk.Window):  
    def __init__(self):  
        super(FileChooserNativeDemo, self).__init__()  
          
        self.init_ui()  
      
    def init_ui(self):  
        self.set_title('File Chooser Native Demo')  
        self.set_default_size(300, 200)  
        self.set_border_width(10)  
          
        button = Gtk.Button('Choose PNG File')  
        button.connect('clicked', self.on_button_clicked)  
        self.add(button)  
      
    def on_button_clicked(self, widget):  
        # 设置默认路径  
        default_path = "/path/to/your/default/directory"  # 替换为你的默认路径  
          
        # 创建文件过滤器  
        filter_png = Gtk.FileFilter()  
        filter_png.set_name("PNG files")  
        filter_png.add_mime_type("image/png")  
          
        # 创建文件选择器对话框  
        dialog = Gtk.FileChooserNative.new("Please choose a PNG file", self,  
                                             Gtk.FileChooserAction.OPEN,  
                                             "_Cancel", "_Open")  
          
        # 设置文件过滤器和默认路径  
        dialog.set_filter(filter_png)  
        dialog.set_current_folder(default_path)  
          
        # 显示对话框并获取用户响应  
        response = dialog.run()  
        if response == Gtk.ResponseType.ACCEPT:  
            filename = dialog.get_filename()  
            print(f"Selected file: {filename}")  # 输出所选文件的路径  
          
        # 销毁对话框  
        dialog.destroy()  
  
if __name__ == '__main__':  
    app = FileChooserNativeDemo()  
    app.connect('destroy', Gtk.main_quit)  
    app.show_all()  
    Gtk.main()
