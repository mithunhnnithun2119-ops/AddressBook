<div align="center">

<img width="100%" src="https://capsule-render.vercel.app/api?type=waving&color=0:0f0c29,50:302b63,100:24243e&height=220&section=header&text=📒%20Address%20Book&fontSize=65&fontColor=ffffff&fontAlignY=40&desc=A%20Console-Based%20Contact%20Management%20System%20in%20C&descAlignY=62&descSize=17&descColor=a78bfa&animation=fadeIn"/>

<img src="https://readme-typing-svg.demolab.com?font=Fira+Code&weight=700&size=20&duration=2500&pause=800&color=A78BFA&center=true&vCenter=true&width=600&lines=📋+Create+%7C+Search+%7C+Update+%7C+Delete;💾+Persistent+File+Storage;🔍+Fast+String-Based+Lookup;🧱+Modular+C+Programming;⚡+Built+from+Scratch+in+Pure+C" alt="Typing SVG" />

<br/>

![Language](https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20Unix-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![Build](https://img.shields.io/badge/Build-GCC-orange?style=for-the-badge&logo=gnu&logoColor=white)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

</div>

---

## 📖 What Is This?

```
┌─────────────────────────────────────────────────────────────────┐
│                                                                 │
│    ██████╗  ██████╗  ██████╗ ██╗  ██╗                         │
│    ██╔══██╗██╔═══██╗██╔═══██╗██║ ██╔╝                         │
│    ██████╔╝██║   ██║██║   ██║█████╔╝                           │
│    ██╔══██╗██║   ██║██║   ██║██╔═██╗                           │
│    ██████╔╝╚██████╔╝╚██████╔╝██║  ██╗                          │
│    ╚═════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═╝                         │
│                                                                 │
│         📒  A D D R E S S   B O O K   v1.0                     │
│         Console-Based Contact Management in C                   │
│                                                                 │
└─────────────────────────────────────────────────────────────────┘
```

> A **fully functional, file-persistent Contact Management System** built entirely in **C** — no external libraries, no frameworks, just clean, modular systems programming.  
> Every contact lives in memory as a **struct**, and on disk as a **structured file** — surviving program restarts, ready when you are.

---

## ✨ Features at a Glance

```c
typedef struct {
    char name[50];
    char phone[15];
    char email[60];
} Contact;

// What this project can do:
// ✅ CREATE   → Add new contacts with name, phone & email
// ✅ READ     → Display all saved contacts in a clean list
// ✅ SEARCH   → Find contacts instantly by name
// ✅ UPDATE   → Edit any field of an existing contact
// ✅ DELETE   → Remove a contact permanently
// ✅ PERSIST  → All data saved to file — survives restarts
```

---

## 🗂️ Project Structure

```
📁 address-book/
│
├── 📄 main.c              → Entry point & menu loop
├── 📄 contact.c           → Core CRUD logic
├── 📄 contact.h           → Struct definitions & function declarations
├── 📄 file_handler.c      → Save & load contacts from disk
├── 📄 file_handler.h      → File operation declarations
├── 📄 utils.c             → String helpers & input validation
├── 📄 utils.h             → Utility declarations
├── 📄 Makefile            → Build automation
└── 📄 contacts.dat        → Persistent data store (auto-created)
```

---

## 🚀 Getting Started

### 🔧 Prerequisites

```bash
# You need GCC installed
gcc --version

# On Ubuntu/Debian
sudo apt install gcc build-essential

# On Fedora
sudo dnf install gcc
```

### 📦 Clone & Build

```bash
# Clone the repository
git clone https://github.com/mithunhnnithun2119-ops/address-book.git
cd address-book

# Build using Makefile
make

# Or compile manually
gcc main.c contact.c file_handler.c utils.c -o addressbook

# Run it!
./addressbook
```

---

## 🖥️ How It Works — Live Demo

```
╔══════════════════════════════════════════╗
║       📒  ADDRESS BOOK  v1.0             ║
║          by Mithun H N                   ║
╠══════════════════════════════════════════╣
║                                          ║
║   [1]  ➕  Add Contact                   ║
║   [2]  📋  Display All Contacts          ║
║   [3]  🔍  Search Contact                ║
║   [4]  ✏️  Update Contact                ║
║   [5]  🗑️  Delete Contact                ║
║   [6]  💾  Save to File                  ║
║   [7]  📂  Load from File                ║
║   [0]  ❌  Exit                          ║
║                                          ║
╚══════════════════════════════════════════╝

Enter your choice: _
```

### ➕ Adding a Contact

```
Enter Name  : Mithun H N
Enter Phone : +91 6360192687
Enter Email : mithunhnmithun2119@gmail.com

✅ Contact added successfully!
```

### 🔍 Searching a Contact

```
Enter name to search: Mithun

┌────────────────────────────────────────┐
│  Name  : Mithun H N                   │
│  Phone : +91 6360192687               │
│  Email : mithunhnmithun2119@gmail.com │
└────────────────────────────────────────┘
```

---

## 🧠 Under the Hood — Technical Deep Dive

### 📌 Data Structure

```c
/* Core contact structure */
typedef struct Contact {
    int    id;           // Unique identifier
    char   name[50];     // Full name
    char   phone[15];    // Phone number
    char   email[60];    // Email address
} Contact;

/* In-memory contact array */
#define MAX_CONTACTS 100
Contact phonebook[MAX_CONTACTS];
int total_contacts = 0;
```

### 🔍 Search Logic

```c
/* String comparison-based search */
Contact* search_contact(const char *name) {
    for (int i = 0; i < total_contacts; i++) {
        if (strcasecmp(phonebook[i].name, name) == 0) {
            return &phonebook[i];   // Return pointer to match
        }
    }
    return NULL;   // Not found
}
```

### 💾 File Persistence

```c
/* Save all contacts to binary file */
void save_to_file(const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) { perror("Error opening file"); return; }

    fwrite(&total_contacts, sizeof(int), 1, fp);
    fwrite(phonebook, sizeof(Contact), total_contacts, fp);
    fclose(fp);
    printf("✅ Contacts saved successfully!\n");
}

/* Load contacts on startup */
void load_from_file(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) return;   // No file yet — fresh start

    fread(&total_contacts, sizeof(int), 1, fp);
    fread(phonebook, sizeof(Contact), total_contacts, fp);
    fclose(fp);
}
```

---

## ⚙️ Core Concepts Used

| Concept | Where Applied |
|--------|--------------|
| `struct` | Contact data model |
| `File I/O` (`fread`/`fwrite`) | Persistent binary storage |
| `Pointers` | Function arguments, struct access, search return |
| `Arrays` | In-memory contact storage |
| `String functions` (`strcpy`, `strcasecmp`) | Name matching & copying |
| `Modular Programming` | Separate `.c` / `.h` files per concern |
| `Command-line Menu` | Interactive loop with `switch-case` |
| `Input Validation` | Prevent buffer overflow on `scanf` |

---

## 🧪 Key Challenges & How I Solved Them

```
❌ Challenge 1: Managing contact records efficiently in memory
✅ Solution   : Used a fixed-size struct array with a global counter
                for O(1) append and O(n) traversal — simple & reliable.

❌ Challenge 2: Saving and retrieving contact details from files
✅ Solution   : Used binary fwrite/fread with the struct directly —
                no parsing needed, fast and portable.

❌ Challenge 3: Search & update with string comparison issues
✅ Solution   : Used strcasecmp() for case-insensitive matching,
                then updated fields via pointer to the found struct.

❌ Challenge 4: Preventing input buffer overflows
✅ Solution   : Used fgets() + sscanf() instead of raw scanf() for
                safe, bounded input reading.
```

---

## 📈 Possible Enhancements

- [ ] 🔤 Sort contacts alphabetically
- [ ] 🔍 Partial/fuzzy name search
- [ ] 📤 Export contacts to `.csv` format
- [ ] 🔐 Password-protect the address book
- [ ] 🖥️ Port to a simple GUI using GTK or ncurses
- [ ] 📱 Add group/category labels to contacts

---

## 👤 Author

<div align="center">

| | |
|--|--|
| **Name** | Mithun H N |
| **Course** | B.E. in ECE — VTU (CGPA: 8.13) |
| **Training** | Advanced Embedded Systems @ Emertxe, Bangalore |
| **Certification** | Skill India / NSDC — ELE/Q1501 |
| **LinkedIn** | [linkedin.com/in/mithun-hn](https://www.linkedin.com/in/mithun-hn) |
| **GitHub** | [github.com/mithunhnnithun2119-ops](https://github.com/mithunhnnithun2119-ops) |
| **Email** | mithunhnmithun2119@gmail.com |

</div>

---

## 📜 License

```
MIT License — Free to use, modify, and distribute.
Give credit where it's due. Happy hacking!
```

---

<div align="center">

<img width="100%" src="https://capsule-render.vercel.app/api?type=waving&color=0:24243e,50:302b63,100:0f0c29&height=120&section=footer&animation=fadeIn"/>

*"Every great system starts with a struct and a plan."* — Mithun H N

![Visitor Count](https://komarev.com/ghpvc/?username=mithunhnnithun2119-ops&color=a78bfa&style=for-the-badge&label=PROFILE+VIEWS)

⭐ **Star this repo if it helped you!** ⭐

</div>
