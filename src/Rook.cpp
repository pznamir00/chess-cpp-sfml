#include "Rook.h"

Rook::Rook(char color, int x, int y) : Figure("rook", color, x, y, left_texture_rect) { this->was_moved = false; }

bool Rook::check_moved() const
{
    return this->was_moved;
}

void Rook::set_moved()
{
    this->was_moved = true;
}

vector<pair<int, int>> Rook::get_available_fields(shared_ptr<Figure> board[][8])
{
    vector<pair<int, int>> available_fields;

    pair<int, int> access_directions[] = { make_pair(0, 1), make_pair(0,-1), make_pair(1, 0), make_pair(-1, 0) };

    for(auto i : access_directions)
    {
        pair<int, int> c = make_pair(i.first, i.second);

        while(true)
        {
            if(this->is_valid_field(this->y + c.first, this->x + c.second))
            {
                if(board[this->y + c.first][this->x + c.second] == nullptr) {
                    available_fields.push_back(make_pair(this->y + c.first, this->x + c.second));
                    c.first += i.first;
                    c.second += i.second;
                    continue;
                }
                else if(board[this->y + c.first][this->x + c.second]->get_color() != this->color)
                    available_fields.push_back(make_pair(this->y + c.first, this->x + c.second));
            }

            break;
        }
    }

    return available_fields;
}
