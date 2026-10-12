#include <vector>
#include <iostream>
#include <numeric>

// solve dynamic connectivity problem using quick find algoritm
class QuickFind
{
private:
    std::vector<int> m_id; // will contain the id of each object 

public:
    explicit QuickFind(int N):
        m_id(N)
    {
        std::iota(m_id.begin(), m_id.end(),0); // initialize id array
    }

    [[nodiscard]] bool connected(int p, int q) const
    {
        return (m_id[p] == m_id[q]);
    }

    void unite(int p, int q)
    {
        const int id_p{ m_id[p] };
        const int id_q{ m_id[q] };
        for (auto& id_i : m_id)
        {
            if ( id_i == id_p)
            {
                id_i = id_q;
            }
        }
    }

};

void printConnected(const QuickFind& qf, int p, int q)
{
    
    std::cout << p << " et " << q << " sont connectés " << qf.connected(p, q) << '\n';
}

int main()
{
    //std::size_t a{10};
    QuickFind qf{-10};
    qf.unite(0, 2);
    printConnected(qf, 3, 4);
    printConnected(qf, 2, 0);
    qf.unite(0, 4);
    printConnected(qf, 2, 4);
    qf.unite(4, 9);
    printConnected(qf, 2, 9);
    return 0;
}