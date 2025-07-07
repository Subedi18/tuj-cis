# CIS 1057: Computer programming in C
Lecture notes, example code, and project files for introductory C programming course.

## Projects
The projects are intended to mimic real-world C codebases at a level that is approachable for introductory students.
### Kabu
A high-performance trade matching and settlement engine, with support for user trading account management.
### Tancho
A satellite telemetry monitoring system, with support for issuing command and control orders.
### Teban
An extensible turn-based game engine which is powerful and flexible enough to implement complicated tabletop games.
<<<<<<< Updated upstream

# Source control
=======
# Project guide
Please refer to this section for guidance on how to seamlessly collaborate on your project with your teammates.

## Source control
>>>>>>> Stashed changes
All projects are contained in a single repository, but the code for each is confined to a branch specific to that project.
- `cis1057-kabu`: Financial trading platform
- `cis1057-tancho`: Satellite telemetry and navigation
- `cis1057-teban`: Turn-based game engine

<<<<<<< Updated upstream
## Initial Setup

After forking the course repository on GitHub:, you need to clone it to your local device.
>⚠️ You only need to do this once! Do not clone the repository multiple times!

### Step 1. Clone your fork
> ⛔️ **DO NOT JUST COPY-PASTE THESE COMMANDS.**

> ⚠️ Replace *YOUR-USERNAME* with your GitHub username, and *YOUR-REPO-NAME* with the name of your forked repo.
```bash
git clone https://github.com/YOUR-USERNAME/YOUR-REPO-NAME.git
cd YOUR-REPO-NAME
```

### Step 2. Add course repo as upstream
Enter this command exactly as you see it below. Copy-paste is okay for this one.
```bash
git remote add upstream https://github.com/profjimhowes/tuj-cis.git
```

### Step 3. Verify remotes
Enter this command:
```bash
git remote -v
```
And you should see something like this:
```bash
origin  https://github.com/tujstudent/tuj-cis (fetch)
origin  https://github.com/tujstudent/tuj-cis (push)
upstream    https://github.com/profjimhowes/tuj-cis (fetch)
upstream    https://github.com/profjimhowes/tuj-cis (push)
```
If you can see both the `origin` and `upstream` repositories listed, then you've successfully set up your local repository for ongoing updates! 🎉

## Staying Up-to-date

=======
### Initial Setup

After forking the course repository on GitHub:

```bash
# Step 1: Clone your fork
git clone https://github.com/your-username/your-repo-name.git
cd your-repo-name

# Step 2: Add course repo as upstream
git remote add upstream https://github.com/profjimhowes/tuj-cis.git

# Step 3: Verify remotes
git remote -v
```

You should see:
- `origin` → your fork
- `upstream` → course repo

### Staying Up-to-date
>>>>>>> Stashed changes
```bash
# Step 1: Fetch Latest Changes
git fetch upstream

# Step 2: Switch to Project Branch
<<<<<<< Updated upstream
git switch cis1057-PROJECTNAME

# Step 3: Pull Upstream Changes
git pull upstream cis1057-PROJECTNAME

# Step 4: Push to Your Fork
git push origin cis1057-PROJECTNAME
```

## Handling Merge Conflicts
=======
git checkout cis1057-projectname

# Step 3: Pull Upstream Changes
git pull upstream cis1057-projectname

# Step 4: Push to Your Fork
git push origin cis1057-projectname
```

### Handling Merge Conflicts
>>>>>>> Stashed changes

Sometimes pulling changes from upstream (step 3 above) will conflict with your work and you need to manually resolve the merge process.

```bash
<<<<<<< Updated upstream
git pull upstream 
=======
git pull upstream cis1057-projectname
>>>>>>> Stashed changes
# Git will show conflict messages

# Edit conflicted files (look for <<<<<<< markers)
# Remove conflict markers and choose the correct code

# After fixing conflicts:
git add .
git commit -m "Merge upstream changes"
```