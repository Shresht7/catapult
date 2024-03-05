# `catapult`

A simple console application to **launch multiple urls** or **applications** simultaneously.

## 💡 Why?

When working on a project, I often have multiple webpages that I want to open together; and stow away when I'm done. While I utilize the _"Restore Last Session"_ feature of the browser, the fact that there can be only _one_ "last" session, limits me to a single project at a time. I usually have an exorbitant amount of tabs open at any given time, but not all of them are relevant to the work I'm doing at the moment. They persist because I need to get back to them later.

Tab-session-manager extensions offer a solution, but I wanted something that would _persist_ the information on the disk - something that I can launch like a url shortcut. This way, the browser workspace can live next to the project files.

## 📘 Usage

> [!NOTE]
> 
> This is technically a command-line application, so you can use it directly from the terminal as shown below, but the main idea was to associate a file extension with this application, so that you can launch the urls directly by double-clicking on the file.

```
catapult.exe <filename>
```

- `filename`: The path to a file containing urls/filepaths to launch.
 
> [!NOTE]
> All this really does is extract the paths from the file and tells the shell to open them. The shell does the rest.

URLs/Paths can be put in any plaintext file (e.g. `.txt`, `.md`, `.catapult`, `.browser-workspace`) on the disk - akin to Internet Shortcut (`.url`) files. For example:

```txt
https://google.com
https://github.com
# This is a comment
```

However, _unlike_ Internet Shortcuts that can only launch one url at a time, this application allows you to specify multiple urls in a single file and launch them all at once.

This allows me to swiftly get back to work, without having to recall the urls I had open for a given project.

### 📄 File Association

#### Windows

When you open a file with an un-encountered extension, Windows will ask you to choose a program to open it with. You can choose an application (you may have to browse to the `.exe`) and check the _"Always use this app to open"_ option to associate the file extension with this application.

From then on, you can simply double-click on the file to launch it using the specified application.

#### Linux

You can achieve the same effect by creating a `.desktop` file and associating it with the file extension. The `.desktop` file can be used to launch the application with the file as an argument.

You may also need to create a MIME type for the custom file extension.

> I'm mostly on the terminal when using linux, so I normally use the command-line there instead of double-clicking the file. That said, desktop file-association can be done.

#### How does this work?

The path to the file is passed as the first argument to the application. The application is designed to take the first argument, read the file, extract the paths and instruct the shell to "start" them. The shell already knows how to handle the urls and the filepaths, so it does the rest.

## 🎯 Objectives

One of the goals of this project was to leverage the _Windows file-association_ mechanism. By specifying a custom file extension (i.e. `.catapult`), that I associate with this application,
I could launch the urls by double-clicking on the file - mirroring the behaviour of a Internet Shortcut (`.url`) file. This allows me to save all the urls for a project to the disk, and launch them all collectively.

I also took the opportunity to write this application in C++. I initially wrote the entire thing in **Go** in about 5 minutes,
and thought to myself, "Maybe I should write this in a language I don't normally use!". So I did. I had only ever used C++ in an academic setting, and never really made anything useful with it.

I thought, it can't get much simpler than this, so why the hell not?

## 📄 License

This project is licensed under the [MIT License](LICENSE.md)
