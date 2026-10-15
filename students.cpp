// Samuel Martin
// 10-14-2026
// ECE-231L Fall 2026 Section Group 1BW
// Project 2
// C++ Student base class (name, GPA, enrollment and graduation info, undergrad/grad) with two derived classes: Art_Student (adds an art emphasis) and Physics_Student (adds a concentration)
// Give each class a default constructor, destructor, and getters/setters
// Then create five of each type with new, store them in two vectors, and write all their info to one file

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

enum Level { UNDERGRAD, GRAD };
enum ArtEmphasis { ART_STUDIO, ART_HISTORY, ART_EDUCATION };
enum PhysicsConcentration { BIOPHYSICS, EARTH_PLANETARY };

// base class: everything common to all students
class Student
{
protected:
    std::string first_name;
    std::string last_name;
    double gpa;
    int grad_year;
    std::string grad_semester;
    int enrolled_year;
    std::string enrolled_semester;
    Level level;

public:
    // default constructor with defaults
    Student()
        : first_name("Unknown"), last_name("Unknown"), gpa(0.0),
          grad_year(0), grad_semester("Unknown"),
          enrolled_year(0), enrolled_semester("Unknown"),
          level(UNDERGRAD)
    {
    }

    // dirtual destructor so derived objects delete correctly through a base pointer
    virtual ~Student()
    {
    }

    // getters
    std::string getFirstName() const { return first_name; }
    std::string getLastName() const { return last_name; }
    double getGPA() const { return gpa; }
    int getGradYear() const { return grad_year; }
    std::string getGradSemester() const { return grad_semester; }
    int getEnrolledYear() const { return enrolled_year; }
    std::string getEnrolledSemester() const { return enrolled_semester; }
    Level getLevel() const { return level; }

    std::string getLevelString() const
    {
        return (level == UNDERGRAD) ? "Undergraduate" : "Graduate";
    }

    // setters
    void setName(const std::string &first, const std::string &last)
    {
        first_name = first;
        last_name = last;
    }
    void setGPA(double g) { gpa = g; }
    void setGPA(const std::string &g) { gpa = std::stod(g); }  // allows setGPA("3.9")
    void setGradYear(int y) { grad_year = y; }
    void setGradSemester(const std::string &s) { grad_semester = s; }
    void setEnrolledYear(int y) { enrolled_year = y; }
    void setEnrolledSemester(const std::string &s) { enrolled_semester = s; }
    void setLevel(Level l) { level = l; }

    // write common info to any output stream
    virtual void write(std::ostream &out) const
    {
        out << "Name: " << first_name << " " << last_name << "\n";
        out << "GPA: " << gpa << "\n";
        out << "Level: " << getLevelString() << "\n";
        out << "Enrolled: " << enrolled_semester << " " << enrolled_year << "\n";
        out << "Graduation: " << grad_semester << " " << grad_year << "\n";
    }
};

// derived class: Art_Student
class Art_Student : public Student
{
private:
    ArtEmphasis art_emphasis;

public:
    Art_Student() : Student(), art_emphasis(ART_STUDIO)
    {
    }

    ~Art_Student()
    {
    }

    ArtEmphasis getArtEmphasis() const { return art_emphasis; }
    void setArtEmphasis(ArtEmphasis e) { art_emphasis = e; }

    std::string getArtEmphasisString() const
    {
        switch (art_emphasis)
        {
        case ART_STUDIO:    return "Art Studio";
        case ART_HISTORY:   return "Art History";
        case ART_EDUCATION: return "Art Education";
        }
        return "Unknown";
    }

    void write(std::ostream &out) const override
    {
        out << "Program: Art\n";
        Student::write(out);
        out << "Art Emphasis: " << getArtEmphasisString() << "\n";
    }
};

// derived class: Physics_Student
class Physics_Student : public Student
{
private:
    PhysicsConcentration concentration;

public:
    Physics_Student() : Student(), concentration(BIOPHYSICS)
    {
    }

    ~Physics_Student()
    {
    }

    PhysicsConcentration getConcentration() const { return concentration; }
    void setConcentration(PhysicsConcentration c) { concentration = c; }

    std::string getConcentrationString() const
    {
        switch (concentration)
        {
        case BIOPHYSICS:      return "Biophysics";
        case EARTH_PLANETARY: return "Earth and Planetary Sciences";
        }
        return "Unknown";
    }

    void write(std::ostream &out) const override
    {
        out << "Program: Physics\n";
        Student::write(out);
        out << "Concentration: " << getConcentrationString() << "\n";
    }
};

int main()
{
    std::vector<Art_Student *> art_students;
    std::vector<Physics_Student *> physics_students;

    // art students
    for (int i = 0; i < 5; i++)
    {
        art_students.push_back(new Art_Student);
    }

    art_students[0]->setName("Frida", "Torres");
    art_students[0]->setGPA("3.9");
    art_students[0]->setEnrolledYear(2022);
    art_students[0]->setEnrolledSemester("Fall");
    art_students[0]->setGradYear(2026);
    art_students[0]->setGradSemester("Spring");
    art_students[0]->setLevel(UNDERGRAD);
    art_students[0]->setArtEmphasis(ART_STUDIO);

    art_students[1]->setName("Georgia", "Begay");
    art_students[1]->setGPA(3.5);
    art_students[1]->setEnrolledYear(2023);
    art_students[1]->setEnrolledSemester("Spring");
    art_students[1]->setGradYear(2027);
    art_students[1]->setGradSemester("Spring");

    art_students[2]->setName("Diego", "Alvarez");
    art_students[2]->setGPA(3.2);
    art_students[2]->setEnrolledYear(2024);
    art_students[2]->setEnrolledSemester("Fall");
    art_students[2]->setGradYear(2026);
    art_students[2]->setGradSemester("Fall");
    art_students[2]->setLevel(GRAD);
    art_students[2]->setArtEmphasis(ART_EDUCATION);

    art_students[3]->setName("Mary", "Cassatt");
    art_students[3]->setGPA(3.75);
    art_students[3]->setEnrolledYear(2021);
    art_students[3]->setEnrolledSemester("Fall");
    art_students[3]->setGradYear(2025);
    art_students[3]->setGradSemester("Fall");
    art_students[3]->setLevel(UNDERGRAD);
    art_students[3]->setArtEmphasis(ART_STUDIO);

    art_students[4]->setName("Jacob", "Lawrence");
    art_students[4]->setGPA(3.1);
    art_students[4]->setEnrolledYear(2025);
    art_students[4]->setEnrolledSemester("Spring");
    art_students[4]->setGradYear(2027);
    art_students[4]->setGradSemester("Spring");
    art_students[4]->setLevel(GRAD);
    art_students[4]->setArtEmphasis(ART_HISTORY);

    // physics students
    for (int i = 0; i < 5; i++)
    {
        physics_students.push_back(new Physics_Student);
    }

    physics_students[0]->setName("Marie", "Curie");
    physics_students[0]->setGPA(4.0);
    physics_students[0]->setEnrolledYear(2022);
    physics_students[0]->setEnrolledSemester("Fall");
    physics_students[0]->setGradYear(2026);
    physics_students[0]->setGradSemester("Spring");
    physics_students[0]->setLevel(UNDERGRAD);
    physics_students[0]->setConcentration(BIOPHYSICS);

    physics_students[1]->setName("Richard", "Feynman");
    physics_students[1]->setGPA("3.8");
    physics_students[1]->setEnrolledYear(2023);
    physics_students[1]->setEnrolledSemester("Fall");
    physics_students[1]->setGradYear(2027);
    physics_students[1]->setGradSemester("Spring");
    physics_students[1]->setLevel(UNDERGRAD);
    physics_students[1]->setConcentration(EARTH_PLANETARY);

    physics_students[2]->setName("Katherine", "Johnson");
    physics_students[2]->setGPA(3.95);
    physics_students[2]->setEnrolledYear(2024);
    physics_students[2]->setEnrolledSemester("Spring");
    physics_students[2]->setGradYear(2026);
    physics_students[2]->setGradSemester("Fall");
    physics_students[2]->setLevel(GRAD);
    physics_students[2]->setConcentration(EARTH_PLANETARY);

    physics_students[3]->setName("Carl", "Sagan");
    physics_students[3]->setGPA(3.6);
    physics_students[3]->setEnrolledYear(2021);
    physics_students[3]->setEnrolledSemester("Fall");
    physics_students[3]->setGradYear(2025);
    physics_students[3]->setGradSemester("Spring");
    physics_students[3]->setLevel(UNDERGRAD);
    physics_students[3]->setConcentration(EARTH_PLANETARY);

    physics_students[4]->setName("Rosalind", "Franklin");
    physics_students[4]->setGPA(3.85);
    physics_students[4]->setEnrolledYear(2025);
    physics_students[4]->setEnrolledSemester("Fall");
    physics_students[4]->setGradYear(2028);
    physics_students[4]->setGradSemester("Spring");
    physics_students[4]->setLevel(GRAD);
    physics_students[4]->setConcentration(BIOPHYSICS);

    // write everything to a single file
    std::ofstream outfile("student_info.dat");
    if (!outfile.is_open())
    {
        std::cerr << "Error: could not open student_info.dat for writing\n";
        return 1;
    }

    outfile << "===== ART STUDENTS =====\n\n";
    for (size_t i = 0; i < art_students.size(); i++)
    {
        art_students[i]->write(outfile);
        outfile << "\n";
    }

    outfile << "===== PHYSICS STUDENTS =====\n\n";
    for (size_t i = 0; i < physics_students.size(); i++)
    {
        physics_students[i]->write(outfile);
        outfile << "\n";
    }

    outfile.close();
    std::cout << "Wrote student information to student_info.dat\n";

    // Free all allocated memory
    for (size_t i = 0; i < art_students.size(); i++)
    {
        delete art_students[i];
    }
    art_students.clear();

    for (size_t i = 0; i < physics_students.size(); i++)
    {
        delete physics_students[i];
    }
    physics_students.clear();

    return 0;
}

