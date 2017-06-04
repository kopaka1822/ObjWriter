#pragma once
#include <fstream>
#include <string>

namespace objwriter
{
	template<class TVertex, class TIndex, class TString, class TStream>
	class ObjWriterT
	{
	public:
		explicit ObjWriterT(TStream& stream) :
			m_file(stream)
		{}

		void comment(const TString& comment)
		{
			m_file << "# " << comment << std::endl;
		}
		void materialLib(const TString& materialLib)
		{
			m_file << "mtllib " << materialLib << std::endl;
		}
		void objectName(const TString& objName)
		{
			m_file << "o " << objName << std::endl;
		}
		void vertex(TVertex v1, TVertex v2, TVertex v3)
		{
			m_file << "v " 
				<< v1 << " "
				<< v2 << " "
				<< v3 << std::endl;
		}
		void vertex(TVertex v1, TVertex v2, TVertex v3, TVertex v4)
		{
			m_file << "v "
				<< v1 << " "
				<< v2 << " "
				<< v3 << " "
				<< v4 << std::endl;
		}
		void texcoord(TVertex t1, TVertex t2)
		{
			m_file << "vt "
				<< t1 << " "
				<< t2 << std::endl;
		}
		void texcoord(TVertex t1, TVertex t2, TVertex t3)
		{
			m_file << "vt "
				<< t1 << " "
				<< t2 << " "
				<< t3 << std::endl;
		}
		void normal(TVertex n1, TVertex n2, TVertex n3)
		{
			m_file << "vn "
				<< n1 << " "
				<< n2 << " "
				<< n3 << std::endl;
		}
		void group(const TString& groupName)
		{
			m_file << "g " << groupName << std::endl;
		}
		void material(const TString& materialName)
		{
			m_file << "usemtl " << materialName << std::endl;
		}
		
		/**
		 * \param level smoothing level between 1 and 32
		 */
		void smoothLevel(int level)
		{
			m_file << "s " << level << std::endl;
		}
		void smoothOff()
		{
			m_file << "s off" << std::endl;
		}
		void face(TIndex i1, TIndex i2, TIndex i3)
		{
			m_file << "f "
				<< i1 << " "
				<< i2 << " "
				<< i3 << std::endl;
		}
		// vertex + normal indices
		void face_vn(TIndex i1, TIndex n1, TIndex i2, TIndex n2, TIndex i3, TIndex n3)
		{
			m_file << "f "
				<< i1 << "//" << n1 << " "
				<< i2 << "//" << n2 << " "
				<< i3 << "//" << n3 << std::endl;
		}
		// vertex + texture indices
		void face_vt(TIndex i1, TIndex t1, TIndex i2, TIndex t2, TIndex i3, TIndex t3)
		{
			m_file << "f "
				<< i1 << "/" << t1 << " "
				<< i2 << "/" << t2 << " "
				<< i3 << "/" << t3 << std::endl;
		}
		// vertex + texture + normal indices
		void face_vtn(TIndex i1, TIndex t1, TIndex n1, TIndex i2, TIndex t2, TIndex n2, TIndex i3, TIndex t3, TIndex n3)
		{
			m_file << "f "
				<< i1 << "/" << t1 << "/" << n1 << " "
				<< i2 << "/" << t2 << "/" << n2 << " "
				<< i3 << "/" << t3 << "/" << n3 << std::endl;
		}
		void parameterVertex(TVertex u, TVertex v)
		{
			m_file << "vp "
				<< u << " "
				<< v << std::endl;
		}
		void parameterVertex(TVertex u, TVertex v, TVertex w)
		{
			m_file << "vp "
				<< u << " "
				<< v << " "
				<< w << std::endl;
		}
	private:
		TStream& m_file;
	};

	using ObjWriter = ObjWriterT<float, int, std::string, std::fstream>;
}
