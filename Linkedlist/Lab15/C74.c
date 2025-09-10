#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Song {
    char title[100];
    char artist[100];
    int duration; // in seconds
    struct Song* prev;
    struct Song* next;
} Song;

struct MusicPlayer {
    Song* current;
    Song* playlist;
} MusicPlayer;

Song* createSong(const char* title, const char* artist, int duration);
void addSong(MusicPlayer* player, const char* title, const char* artist, int duration);
void playCurrent(Song* song);
void playNext(MusicPlayer* player);
void playPrevious(MusicPlayer* player);
void displayPlaylist(Song* playlist);
void removeSong(MusicPlayer* player, const char* title);
void freePlaylist(Song* playlist);

int main() {
    MusicPlayer player = {NULL, NULL};
    int choice;
    char title[100], artist[100];
    int duration;

    printf("=== Music Player Simulation ===\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Song\n");
        printf("2. Play Current Song\n");
        printf("3. Play Next Song\n");
        printf("4. Play Previous Song\n");
        printf("5. Display Playlist\n");
        printf("6. Remove Song\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer

        switch (choice) {
            case 1:
                printf("Enter song title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove newline
                printf("Enter artist: ");
                fgets(artist, sizeof(artist), stdin);
                artist[strcspn(artist, "\n")] = '\0';
                printf("Enter duration (seconds): ");
                scanf("%d", &duration);
                addSong(&player, title, artist, duration);
                break;
            case 2:
                if (player.current) {
                    playCurrent(player.current);
                } else {
                    printf("No song selected!\n");
                }
                break;
            case 3:
                playNext(&player);
                break;
            case 4:
                playPrevious(&player);
                break;
            case 5:
                displayPlaylist(player.playlist);
                break;
            case 6:
                printf("Enter song title to remove: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0';
                removeSong(&player, title);
                break;
            case 7:
                freePlaylist(player.playlist);
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}

// Create a new song node
Song* createSong(const char* title, const char* artist, int duration) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->duration = duration;
    newSong->prev = NULL;
    newSong->next = NULL;
    return newSong;
}

// Add song to the end of playlist
void addSong(MusicPlayer* player, const char* title, const char* artist, int duration) {
    Song* newSong = createSong(title, artist, duration);
    
    if (player->playlist == NULL) {
        player->playlist = newSong;
        player->current = newSong;
    } else {
        Song* last = player->playlist;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newSong;
        newSong->prev = last;
    }
    
    printf("Added '%s' to playlist.\n", title);
}

// Play the current song
void playCurrent(Song* song) {
    printf("\nNow Playing:\n");
    printf("Title: %s\n", song->title);
    printf("Artist: %s\n", song->artist);
    printf("Duration: %d:%02d\n", song->duration/60, song->duration%60);
}

// Play next song
void playNext(MusicPlayer* player) {
    if (player->current == NULL) {
        printf("No songs in playlist!\n");
        return;
    }
    
    if (player->current->next == NULL) {
        printf("End of playlist reached.\n");
    } else {
        player->current = player->current->next;
        playCurrent(player->current);
    }
}

// Play previous song
void playPrevious(MusicPlayer* player) {
    if (player->current == NULL) {
        printf("No songs in playlist!\n");
        return;
    }
    
    if (player->current->prev == NULL) {
        printf("Beginning of playlist reached.\n");
    } else {
        player->current = player->current->prev;
        playCurrent(player->current);
    }
}

// Display all songs in playlist
void displayPlaylist(Song* playlist) {
    if (playlist == NULL) {
        printf("Playlist is empty!\n");
        return;
    }
    
    printf("\nPlaylist:\n");
    Song* current = playlist;
    int i = 1;
    while (current != NULL) {
        printf("%d. %s - %s (%d:%02d)\n", i++, 
               current->title, current->artist, 
               current->duration/60, current->duration%60);
        current = current->next;
    }
}

// Remove a song from playlist
void removeSong(MusicPlayer* player, const char* title) {
    Song* current = player->playlist;
    bool found = false;
    
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            found = true;
            
            // Update neighbors' pointers
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                player->playlist = current->next;
            }
            
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            
            // Update current pointer if needed
            if (player->current == current) {
                if (current->next != NULL) {
                    player->current = current->next;
                } else if (current->prev != NULL) {
                    player->current = current->prev;
                } else {
                    player->current = NULL;
                }
            }
            
            printf("Removed '%s' from playlist.\n", title);
            free(current);
            break;
        }
        current = current->next;
    }
    
    if (!found) {
        printf("Song '%s' not found in playlist.\n", title);
    }
}

// Free all memory used by playlist
void freePlaylist(Song* playlist) {
    Song* current = playlist;
    while (current != NULL) {
        Song* temp = current;
        current = current->next;
        free(temp);
    }
}