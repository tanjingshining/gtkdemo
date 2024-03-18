#include <gtk/gtk.h>

// 回调函数，当用户选择文件后调用
void on_file_selected(GtkFileChooserNative *chooser, gpointer user_data) {
    g_print("File selected: %s\n", gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(chooser)));
    gtk_widget_destroy(GTK_WIDGET(chooser)); // 关闭文件选择器
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv); // 初始化GTK+库

    GtkWidget *window = gtk_application_window_new(NULL); // 创建主窗口
    gtk_window_set_title(GTK_WINDOW(window), "File Chooser Demo"); // 设置窗口标题
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200); // 设置窗口默认大小
    gtk_container_set_border_width(GTK_CONTAINER(window), 10); // 设置窗口边框宽度

    GtkFileChooserNative *native;
    GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;
    gint res;

    native = gtk_file_chooser_native_new ("Open File",
                                          GTK_WINDOW(window),
                                          action,
                                          "_Open",
                                          "_Cancel");


    // 设置文件选择器的过滤器，只显示文本文件（可选）
    GtkFileFilter *filter = gtk_file_filter_new();
    gtk_file_filter_add_mime_type(filter, "text/plain");
    gtk_file_chooser_set_filter(GTK_FILE_CHOOSER(native), filter);

    res = gtk_native_dialog_run (GTK_NATIVE_DIALOG (native));
    if (res == GTK_RESPONSE_ACCEPT)
      {
        char *filename;
        GtkFileChooser *chooser = GTK_FILE_CHOOSER (native);
        filename = gtk_file_chooser_get_filename (chooser);
        g_print("File selected: %s\n", filename);
//        open_file (filename);
//        g_free (filename);
      }

    g_object_unref (native);

    // 显示文件选择器
    gtk_widget_show_all(GTK_WIDGET(native));

    // 显示主窗口（虽然在这个demo中我们不会使用它，但在实际应用中你可能会需要它）
    gtk_widget_show_all(window);

    // 进入GTK+主循环
    gtk_main();

    return 0;
}
