# `catapult`

A simple console application to **launch multiple urls** at once in the default browser.

## 💡 Why?

When working on a project, I often have multiple urls that I want to open together; and stow away when I'm done. While I utilize the "Restore Last Session" feature in my browser, it limits me to a single project at a time. I have an exorbitant amount of tabs open at any given time, but not all of them are relevant to the work I'm doing at the moment. They persist because I need to get back to them later.

Tab-session-manager extensions offer a solution, but I wanted something that would persist the information on the disk. This way, my browser workspace lives next to the project files.

## 📘 Usage

```
catapult.exe <filename>
```

- `filename`: The path to a file containing urls to launch.

> [!NOTE]
>
> All this really does is extract urls from the file and tell the shell to open them. The shell does the rest and opens them in the default browser.

Urls can be put in any plaintext file (e.g. `.txt`, `.md`, `.catapult`) on the disk - similar to Internet Shortcut (`.url`) files.
But unlike Internet Shortcuts that can only launch one url at a time, this application allows you to specify multiple urls in a single file and launch them all at once.

This allows me to get back to work as quickly as possible, without having to remember which urls I had open for a given project.

## 🎯 Objectives

One of the goals was to make use of the _Windows file-association_ mechanism. By specifying a custom file extension (i.e. `.catapult`), that I associate with this application,
I could launch the urls by double-clicking on the file - just like I would with a Internet Shortcut (`.url`) file. This allows me to save all the urls for a project to the disk, and launch them all at once.

I also took the opportunity to write this application in C++. I initially wrote the entire thing in **golang** in about 15 minutes,
and thought to myself, "Maybe I should write this in a language I don't normally use!". So I did. I had only ever used C++ in an academic setting, and never really made anything useful with it.
I thought, it can't get much simpler than this, so why the hell not?

## 📄 License

This project is licensed under the [MIT License](LICENSE.md).
