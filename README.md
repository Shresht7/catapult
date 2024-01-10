# `catapult`

A simple console application to **launch multiple urls** in the default browser.

Urls can be put in any plaintext file (e.g. `.txt`, `.md`, `.catapult`) on the disk - similar to Internet Shortcut (`.url`) files.
But unlike Internet Shortcuts that can only launch one url at a time, this application allows you to specify multiple urls in a single file and launch them all at once.
This allows me to get back to work as quickly as possible, without having to remember which urls I had open for a given project.

When working on a project, I often have multiple urls that I want to open together; and stow away when I'm done. I do use the "Restore Last Session" feature on my browser,
but it only works for one project at a time. I wanted to be able to switch between projects as effortlessly I switch branches in a git repository.

Similar functionality exists in tab-session-manager extensions, but I wanted to persist the information on the disk. This way, my browser workspace lives next to the project files.

## 🎯 Objectives

One goal was to make use of the _Windows file-association_ mechanism. By specifying a custom file extension (e.g. `.catapult`), that I associate with this application,
I can launch the urls by double-clicking on the file - just like I would with a Internet Shortcut (`.url`) file.

I also took the opportunity to write this application in C++. I wrote the entire thing using go in about 15 minutes,
and thought to myself, "I should write this in a language I don't normally use!". So I did. I had only ever used C++ in an academic setting, and never really made anything useful with it.
I thought, it can't get much simpler than this, so why the hell not?

## 📄 License

This project is licensed under the [MIT License](LICENSE.md).