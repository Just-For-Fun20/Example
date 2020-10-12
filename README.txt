Описание классов проекта.

Проект построен на основе шаблона проектирования MVC.
Состоит из 3 классов: 
	-TZipViewerModel
	-TController
	-MainWindow
	
Класс TZipViewerModel с помощью библиотеки minizip открывает архив с помощью функции openZipFile();
Хранит в себе вектор пар <имя_файла_в_архиве, размер_файла_в_байтах>, а так же имя архива.

Класс TController связывает классы TZipViewerModel и MainWindow.

Класс MainWindow содержит в себе форму и сигналы. Передаёт в TController имя файла, и получает взамен от TZipViewerModel пару <имя_файла_в_архиве, размер_файла_в_байтах> для вывода в tableInfoWidget;