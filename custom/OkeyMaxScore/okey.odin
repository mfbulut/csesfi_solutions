#+feature dynamic-literals
package main

import "core:fmt"

// TODO: Get input from stdin
tiles : [][2]int = {
    {1, 1}, {1, 2}, {1, 3}, {1, 4},
    {2, 3}, {2, 4}, {2, 5},
    {3, 5}, {3, 6}, {3, 7},
    {4, 7}, {4, 8}, {4, 9},
    {1, 10}, {2, 10}, {3, 10}, {4, 10},
    {1, 12}, {2, 12}, {3, 12}, {4, 12}
}

Tile :: struct {
    c: int,
    v: int,
}

tile_map : [4][13]int
groups : [dynamic][dynamic]Tile

main :: proc() {
    for tile in tiles {
        tile_map[tile[0] - 1][tile[1] - 1] += 1
    }
    
    for line, c in tile_map {
        fmt.println(line)
    
        // Runs of 3
        for i in 0..<11 {
            if(line[i] > 0 && line[i + 1] > 0 && line[i + 2] > 0) {
                append(&groups, [dynamic]Tile{{c, i}, {c, i + 1}, {c, i + 2}})
            }
        }
        
        // Runs of 4
        for i in 0..<10 {
            if(line[i] > 0 && line[i + 1] > 0 && line[i + 2] > 0 && line[i + 3] > 0) {
                append(&groups, [dynamic]Tile{{c, i}, {c, i + 1}, {c, i + 2}, {c, i + 3}})
            }
        }
        
        // Runs of 5
        for i in 0..<9 {
            if(line[i] > 0 && line[i + 1] > 0 && line[i + 2] > 0 && line[i + 3] > 0 && line[i + 4] > 0) {
                append(&groups, [dynamic]Tile{{c, i}, {c, i + 1},{c, i + 2}, {c, i + 3}, {c, i + 4}})
            }
        }
    }
    
    fmt.println()
    
    // Sets (Different Colors, Same Value)
    for i in 0..<13 {
        red := tile_map[0][i] > 0
        blue := tile_map[1][i] > 0
        yellow := tile_map[2][i] > 0
        black := tile_map[3][i] > 0
        
        // 4 Colors
        if(red && blue && yellow && black) {
            append(&groups, [dynamic]Tile{{0, i}, {1, i}, {2, i}, {3, i}})
        }
        
        // 3 Colors Combinations
        if(red && blue && yellow) {
            append(&groups, [dynamic]Tile{{0, i}, {1, i}, {2, i}})
        }
        if(red && blue && black) {
            append(&groups, [dynamic]Tile{{0, i}, {1, i}, {3, i}})
        }
        if(red && yellow && black) {
            append(&groups, [dynamic]Tile{{0, i}, {2, i}, {3, i}})
        }
        if(blue && yellow && black) {
            append(&groups, [dynamic]Tile{{1, i}, {2, i}, {3, i}})
        }
    }
    
    max_score := 0
    
    indices: [dynamic]int
    tile_map_copy : [4][13]int
    max_mask := uint(1) << len(groups)
    
    combinations: for mask in 1..<max_mask {
        clear(&indices)
        tile_map_copy = tile_map
        
        sum := 0
        
        for group, i in groups {
            if (mask & (1 << uint(i))) != 0 {
                for tile in group {
                    if tile_map_copy[tile.c][tile.v] == 0 {
                        continue combinations
                    }
                }
                
                for tile in group {
                    tile_map_copy[tile.c][tile.v] -= 1
                    sum += tile.v + 1
                }
                
                append(&indices, i)
            }
        }
        
        max_score = max(max_score, sum)
        
        print_solution(indices)
    }
    
    fmt.println(max_score)
}

print_solution :: proc(indices: [dynamic]int) {
    colors := []string{"Red", "Blue", "Yellow", "Black"}
    sum := 0
    
    for group_id in indices {
        fmt.print("[")
        group := groups[group_id]
        
        for tile, i in group {
            value := tile.v + 1
            sum += value
            fmt.printf("%v %v", colors[tile.c], value)
            if i < len(group) - 1 do fmt.print(", ")
        }
        fmt.print("] ")
    }
    
    fmt.printf("\nSum: %v\n\n", sum)
}